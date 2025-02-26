/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/22 16:20:03 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

//use dup2 for file redirection

//execute the command before redirecting it into the file 

char	*find_executables(const char *cmd) //article stackoverflow
//search for the command in each directory listed in PATH

char	**parse_command(const char *cmd)
{
	char	**
	//split the command into an array of strings, handling spaces and quotes.
}


//piping: create a pipe
// fork for the first command 
//fork for the second command
//connect the pipe between the commands. 


//check the result of all the system calls like open, pipe, fork, execve, etc.

int main(int argc, char **argv, )
{
	
	int		fd[2];
	pid_t	pid;
	char	buf;

	pipe(fd);
	if (pipe == -1)
	{
		perror("pipe");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		
	}
	

}
