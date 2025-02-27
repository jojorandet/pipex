/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:10:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/27 18:22:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*duplicate;
	char	*cursor;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
		return (NULL);
	duplicate = (char *)malloc(sizeof(*duplicate) * len);
	if (!duplicate)
		return (NULL);
	cursor = duplicate;
	while (*s && n--)
		*cursor++ = *s++;
	*duplicate = '\0';
	return (duplicate);
}

int	ft_strlen(char *s)
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

char	*ft_calloc(size_t nb_elements, size_t size)
{
	char	*result;
	size_t	memory_needed;

	memory_needed = nb_elements * size;
	result = (char *)malloc(memory_needed);
	if (!result)
		return (NULL);
	
	
}
