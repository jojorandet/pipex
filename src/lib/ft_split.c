/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:19:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/09 19:41:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_count_words(char *s, char c)
{
	size_t	count_words;

	count_words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count_words++;
		while (*s && *s != c)
			s++;
	}
	return (count_words);
}

static char	**fill_array(char *s, char **array, char c)
{
	char	*end;
	char	*sdup_str;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		end = s;
		while (*end && *end != c)
			end++;
		if (s != end)
		{
			sdup_str = ft_strndup(s, end - s);
			if (!sdup_str)
			{
				clean_array(array);
				return (NULL);
			}
			array[i++] = sdup_str;
		}
		s = end;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char *s, char c)
{
	int		count_words;
	char	**split_array;

	count_words = 0;
	if (!s || s[0] == '\0')
		return (ft_calloc(1, sizeof(char *)));
	count_words = ft_count_words(s, c);
	split_array = ft_calloc(count_words + 1, sizeof(char *));
	if (!split_array)
		return (NULL);
	return (fill_array(s, split_array, c));
}

//need to return the empty string