/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:42:15 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/02 12:10:23 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_parent_process(t_pipex *pipex, char **argv)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
		error_display(pipex, "Error creating output file.");
	close(pipex->pipefd[1]);
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1
		|| dup2(fd_out, STDOUT_FILENO) == -1)
		error_display(pipex, "Error: Parent dup2.");
	close(fd_out);
	close(pipex->pipefd[0]);
}

void	redirect_child_process(t_pipex *pipex, char **argv)
{
	int	fd_in; // this file descriptor uniquely identifies an open file in a process 

	fd_in = open(argv[1], O_RDONLY, 0644); //i need to open the file descriptor of the file 
	if (fd_in < 0)
		error_display(pipex, "Error opening input file.");
	close(pipex->pipefd[0]);
	if (dup2(fd_in, STDIN_FILENO) == -1 
		|| dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
	{
		error_display(pipex, "Error: child dup2");
		return ;
	}
	close(fd_in);
	close(pipex->pipefd[1]);
}

//permission : owner (your program) had read and write permissions (allows the user who created and ran the program to edit the file)
//group members and other users have read only rights (allows the users to view the output)
//prevents accidental modifications to people who did not create the file.

//dup2(old fd, new fd)
//new fd is closed first if it was already open
//newfd becomes a copy of the old fd (in our case the write end of the pipe)
//after the call, the old file descriptor and the new file des can be used interchangeably
//they share the same file position. 

//un des file descriptor est en mode RDONLY et l'autre en WRONLY
// we get fd[0] the read end of a pipe
//we get fd[1] the write only enf of a pipe. 
//they ate limited resources and you need to close one when not using it. 
//they communicate with eachother. the read end of a file only detect an EOF when the write ends are closed.
//if we dont use close unused rite ends, a process will hang waiting for the data
//if the read end is closed, it will send a SIGPIPE.