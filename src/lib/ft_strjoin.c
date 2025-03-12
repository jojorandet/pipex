/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:55:24 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/12 15:23:24 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*j_s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j_s = malloc(sizeof(*j_s) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!j_s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		j_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		j_s[i] = s2[j];
		i++;
		j++;
	}
	j_s[i] = '\0';
	return (j_s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*src_start;

	src_start = src;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(src_start));
}
