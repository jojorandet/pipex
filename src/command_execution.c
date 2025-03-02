/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:31:19 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/02 16:39:03 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char	**get_paths(char **env)
{
	char	*line;

	while (*env && !(ft_start_with(*env, "PATH=")))
		env++;
	if (!env)
		return (NULL);
	line = *env;
	return (ft_split(line + 5, ':'));
}

void	execute_command(char *command, char **env)
{
	char	**paths;
	(void)command;

	paths = get_paths(env);
	print_string_array(paths);
	free(paths);
}

