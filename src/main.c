/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/03 12:07:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

void	print_string_array(char **s)
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
