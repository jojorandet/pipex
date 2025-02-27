/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:47:44 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/28 11:51:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_pid(char **argv, char **env)
{
	t_pipex	pipex;

	(void)env;
	(void)argv;
	if (pipe(pipex.pipefd) == -1)
		error_display(&pipex, "Pipe could not be created\n");
	pipex.pid = fork();
	if (pipex.pid == -1)
		error_display(&pipex, "Child process could not be created\n");
	if (pipex.pid == 0)
	{
		redirect_child_process(&pipex, argv);
		//execute_cmd(argv[2], env);
	}
	return ;
}
