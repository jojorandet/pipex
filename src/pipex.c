/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:47:44 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/08 19:47:42 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex_init(t_pipex *pipex, char ** argv, char **env)
{
	(void)env;
	
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
		pipex_exit(pipex, "Error: fd_in could not be accessed!\n");
	pipex->fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (pipex->fd_out == -1)
	{
		close(pipex->fd_in);
		pipex_exit(pipex, "Error: fd_out could not be accessed!\n");
	}
	/*pipe(pipex->pipefd);
	if (pipe(pipex->pipefd) == -1)
	{
		close(pipex->fd_in);
		close(pipex->fd_out);
		pipex_exit(pipex, "Pipe could not be created\n");
	}
	pipex->env = env;
	command_init(pipex, &pipex->cmd1, argv[2]);
	command_init(pipex, &pipex->cmd2, argv[3]);*/
}
void	init_cmds(char **argv, char **env)
{
	t_pipex		pipex;

	pipex_init(&pipex, argv, env);
	/*execute_command(&pipex.cmd1, pipex.fd_in, pipex.pipefd[1], pipex.pipefd[0]);
	execute_command(&pipex.cmd2, pipex.pipefd[0], pipex.fd_out, pipex.pipefd[1]);
	waitpid(pipex.cmd1.pid, &pipex.cmd1.status, 0);
	waitpid(pipex.cmd2.pid, &pipex.cmd2.status, 0);
	if (pipex.cmd1.status)
		pipex_exit(&pipex, "Cmd1 has failed execve.\n");
	if (pipex.cmd2.status)
		pipex_exit(&pipex, "Cmd2 has failed execve.\n");
	pipex_exit(&pipex, NULL);*/
}
