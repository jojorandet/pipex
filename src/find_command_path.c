/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:31:19 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/09 21:06:03 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*create_path_array(char *str1, char *str2)
{
	int		path_len;
	char	*path;
	char	*current;

	if (!str1 || !str2)
		return (NULL);
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

static char	*clean_and_return(char **array_of_paths, char *value_to_return)
{
	clean_array(array_of_paths);
	return (value_to_return);
}

static char	*find_and_free_paths(char **array_of_paths, char *command)
{
	char	**current;
	char	*final_path;

	if (!command || !*command)
		return (clean_and_return(array_of_paths, NULL));
	current = array_of_paths;
	while (*current)
	{
		final_path = create_path_array(*current, command);
		if (!final_path)
			return (clean_and_return(array_of_paths, NULL));
		if (access(final_path, F_OK) == 0)
			return (clean_and_return(array_of_paths, final_path));
		free(final_path);
		current++;
	}
	return (clean_and_return(array_of_paths, NULL));
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
	command_path = find_and_free_paths(array_of_paths, command);
	if (!command_path)
		pipex_exit(pipex, "Error: Command not found or empty command provided.\n");
	return (command_path);
}
