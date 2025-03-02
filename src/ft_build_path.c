/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:41:30 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/02 17:37:06 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_build_path(char *str1, char *str2)
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
