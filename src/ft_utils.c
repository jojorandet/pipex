/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:10:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/03 11:51:52 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

bool	ft_start_with(char *str, char *start)
{
	while (*str && *start)
	{
		if (*str != *start)
			return (false);
		str++;
		start++;
	}
	if (*start)
		return (false);
	return (true);
}

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