/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:10:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/11 15:39:47 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
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

void	ft_puterr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(2, s++, 1);
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

char	*ft_strdup(char *s)
{
	char	*duplicate;
	char	*cursor;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
		return (handle_empty_string());
	duplicate = (char *)malloc(sizeof(*duplicate) * (len + 1));
	if (!duplicate)
		return (NULL);
	cursor = duplicate;
	while (*s)
		*cursor++ = *s++;
	*cursor = '\0';
	return (duplicate);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
