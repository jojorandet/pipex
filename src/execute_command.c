/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:35:08 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/03 18:57:05 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(t_command *cmd, int	fd_in, int fd_out, int fd_to_close)
{
	cmd->pid = fork();
	if (cmd->pid == -1)
		pipex_exit(cmd->pipex, "Error: fork failed!\n");
	if (cmd->pid != 0)
	{
		close(fd_in);
		close(fd_out);
		return ;
	}
	close(fd_to_close);
	if (dup2(fd_in, STDIN_FILENO) == -1 || dup2(fd_out, STDOUT_FILENO) == -1)
		pipex_exit(cmd->pipex, "Error: dup2 failed\n");
	if (close(fd_in) == -1 || close(fd_out) == -1)
		pipex_exit(cmd->pipex, "Error closing pipes in child process.");
	if (execve(cmd->path, cmd->args, cmd->pipex->env) == -1)
		pipex_exit(cmd->pipex, "Error! execve process failed.\n");
}
