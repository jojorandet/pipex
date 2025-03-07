/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:31:19 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/03 19:03:24 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_build_path(char *str1, char *str2)
{
	int		path_len;
	char	*path;
	char	*current;

	path_len = ft_strlen(str1) + ft_strlen(str2);
	path = (char *)malloc(sizeof(char) * (path_len + 2));
	if (!path)
		return (NULL);
	path[path_len + 1] = '\0';
	current = path;
	while (*str1)
		*current++ = *str1++;
	*current++ = '/';
	while (*str2)
		*current++ = *str2++;
	return (path);
}

static char	*get_executable_path(char **array_of_paths, char *command)
{
	char	**current;
	char	*final_path;
	
	current = array_of_paths;
	while (*current)
	{
		final_path = ft_build_path(*current, command);
		if (!final_path)
		{
			clean_array(array_of_paths);
			return (NULL);
		}
		if (access(final_path, F_OK) == 0)
		{
			clean_array(array_of_paths);
			return (final_path);
		}
		free(final_path);
		current++;
	}
	if (!*array_of_paths)
		clean_array(array_of_paths);
	return (NULL);
}

static char	**split_path_command(char **env)
{
	char	*line;

	while (*env && !(ft_start_with(*env, "PATH=")))
		env++;
	if (!env)
		return (NULL);
	line = *env;
	return (ft_split(line + 5, ':'));
}

char	*find_command_path(t_pipex *pipex, char *command)
{
	char	**array_of_paths;
	char	*command_path;

	array_of_paths = split_path_command(pipex->env);
	if (!array_of_paths)
		return (NULL);
	command_path = get_executable_path(array_of_paths, command);
	if (!command_path)
	{
		clean_array(array_of_paths);
		pipex_exit(pipex, "Error! Unable to alocate command path array.");
	}
	return (command_path);
}
