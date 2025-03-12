/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:35:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/12 15:11:11 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	connect_pipe(t_command *cmd)
{
	set_up_command_input(cmd);
	set_up_command_output(cmd);
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
		if (pipe(p->fildes) == -1)
			pipex_exit(pipex, "pipe failed\n");
		pipex->cmds[i].pipe_out = p;
		pipex->cmds[i + 1].pipe_in = p;
		execute_command(pipex->cmds + i);
		i++;
	}
	execute_command(pipex->cmds + i);
}
