/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:44:16 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/09 18:43:20 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*handle_empty_string(void)
{
	char	*duplicate;

	duplicate = (char *)malloc(sizeof(*duplicate) * 1);
	if (!duplicate)
		return (NULL);
	duplicate[0] = '\0';
	return (duplicate);
}

char	*ft_strndup(char *s, size_t n)
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
	while (*s && n--)
		*cursor++ = *s++;
	*cursor = '\0';
	return (duplicate);
}
