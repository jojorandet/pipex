/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:04:00 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/12 15:18:29 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_command *cmd, int fd)
{
	if (close(fd) == -1)
		pipex_exit(cmd->pipex, "fd not closed");
}

void	dup_fd(t_command *cmd, int fd, int fd2)
{
	if (dup2(fd, fd2) == -1)
	{
		printf("failed\n");
		pipex_exit(cmd->pipex, "Dup2 failed\n");
	}
	close_fd(cmd, fd);
}

void	set_up_command_input(t_command *cmd)
{
	if (!cmd->pipe_in)
	{
		if (!(cmd->pipex->is_heredoc && cmd == &cmd->pipex->cmds[0]))
		{
			if (cmd->pipex->fd_in < 0)
				pipex_exit(cmd->pipex, "Invalid input file descriptor\n");
			dup_fd(cmd, cmd->pipex->fd_in, STDIN_FILENO);
		}
	}
	else
	{
		if (cmd->pipex->fd_in >= 0)
			close_fd(cmd, cmd->pipex->fd_in);
		if (cmd->pipe_in)
			close_fd(cmd, cmd->pipe_in->write);
		dup_fd(cmd, cmd->pipe_in->read, STDIN_FILENO);
	}
}

void	set_up_command_output(t_command *cmd)
{
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
