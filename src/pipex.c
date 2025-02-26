/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:41:31 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/26 13:37:42 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

void	parse_ccommand(int argc, char **argv)
{
	
}

int main(int argc, char **argv, char **env)
{
	int     fd[2];
	pid_t   pid;
	int     ex;

	if (argc < 5)
		return (1);
	parse_command(argc, argv, env);


	pipe(fd);// creates 
	if (pipe == -1)
	{
		perror("pipe");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		ex = execute_child_process();
	}
	

}
