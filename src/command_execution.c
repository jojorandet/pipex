/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:31:19 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/02 19:03:47 by jrandet          ###   ########.fr       */
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

char	*get_path(char *command, char **env)
{
	char	**paths;
	char	**current;
	char	*final_path;

	paths = get_paths(env);
	if (!paths)
		return (NULL);
	current = paths;
	while (*current)
	{
		final_path = ft_build_path(*current, command);
		if (!final_path)
		{
			clean_array(paths);
			return (NULL);
		}
		if (access(final_path, F_OK) == 0)
		{
			printf("access entered, final path: %s\n", final_path);
			clean_array(paths);
			return (final_path);
		}
		current++;
	}
	if (!*paths)
		clean_array(paths);
	return (NULL);
}

void	execute_command(char *command, char **env)
{
	char	*command_path;

	command_path = get_path(command, env);
	if (!command_path)
		return ;
	printf("final path is %s\n", command_path);
}
