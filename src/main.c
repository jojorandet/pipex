/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/26 16:22:37 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

//use dup2 for file redirection

//execute the command before redirecting it into the file 

/*char	*find_executables(const char *cmd) //article stackoverflow*/
//search for the command in each directory listed in PATH

/*char	**parse_command(const char *cmd)
{
	char	**
	//split the command into an array of strings, handling spaces and quotes.
}*/

//piping: create a pipe
// fork for the first command 
//fork for the second command
//connect the pipe between the commands. 

//check the result of all the system calls like open, pipe, fork, execve, etc.

int	main(int argc, char **argv, char **envp)
{
	if (!ft_parsing(argc, argv))
	{
		write(2, "Error! input is invalid. infile cmd1 | cmd2 outfile\n", 53);
		exit(EXIT_FAILURE);
	}
}
