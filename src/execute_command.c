/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:35:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/09 18:40:33 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fd(t_command *cmd, int fd)
{
	if (close(fd) == -1)
		pipex_exit(cmd->pipex, "fd not closed");
}

static void	dup_fd(t_command *cmd, int fd, int fd2)
{
	if (dup2(fd, fd2) == -1)
		pipex_exit(cmd->pipex, "Dup2 failed\n");
	close_fd(cmd, fd);
}

static void	connect_pipe(t_command *cmd)
{
	if (!cmd->pipe_in)
	{
		dup_fd(cmd, cmd->pipex->fd_in, STDIN_FILENO);
	}
	else
	{
		close_fd(cmd, cmd->pipex->fd_in);
		close_fd(cmd, cmd->pipe_in->write);
		dup_fd(cmd, cmd->pipe_in->read, STDIN_FILENO);
	}
	if (!cmd->pipe_out)
	{
		dup_fd(cmd, cmd->pipex->fd_out, STDOUT_FILENO);
	}
	else
	{
		close_fd(cmd, cmd->pipex->fd_out);
		close_fd(cmd, cmd->pipe_out->read);
		dup_fd(cmd, cmd->pipe_out->write, STDOUT_FILENO);
	}
}

static void	execute_command(t_command *cmd)
{
	char	*exec_path;

	cmd->pid = fork();
	if (cmd->pid == -1)
		pipex_exit(cmd->pipex, "Error: fork failed!\n");
	if (cmd->pid != 0)
	{
		if (cmd->pipe_in)
		{
			close_fd(cmd, cmd->pipe_in->read);
			close_fd(cmd, cmd->pipe_in->write);
		}
		return ;
	}
	connect_pipe(cmd);
	exec_path = find_command_path(cmd->pipex, cmd->args[0]);
	if (!exec_path)
		pipex_exit(cmd->pipex, "executable not found!\n");
	if (execve(exec_path, cmd->args, cmd->pipex->env) == -1)
	{
		free(exec_path);
		pipex_exit(cmd->pipex, "Error! execve process failed.\n");
	}
}

void	execute_pipe(t_pipex *pipex)
{
	int		i;
	t_pipe	*p;

	i = 0;
	while (pipex->cmds[i + 1].args != NULL)
	{
		p = pipex->pipes + i;
		pipe(p->fildes);
		pipex->cmds[i].pipe_out = p;
		pipex->cmds[i + 1].pipe_in = p;
		execute_command(pipex->cmds + i);
		i++;
	}
	execute_command(pipex->cmds + i);
}
