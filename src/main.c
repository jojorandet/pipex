/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/28 11:28:49 by jrandet          ###   ########.fr       */
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




void	print_double_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{	
	(void)argc;
	if (!ft_parsing(argc, argv))
	{
		write(2, "Invalid input! filein cmd1 | cmd2 fileout\n", 43);
		exit(EXIT_FAILURE);
	}
	get_pid(argv, env);
	return (0);
}
