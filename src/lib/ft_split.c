/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:19:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/10 11:54:36 by jrandet          ###   ########.fr       */
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

static int	fill_with_dup(char ***ptr_to_arr, char *s, char *end, \
						size_t *ptr_to_i)
{
	char	*sdup_str;

	sdup_str = ft_strndup(s, end - s);
	if (!sdup_str)
	{
		clean_array(*ptr_to_arr);
		return (0);
	}
	(*ptr_to_arr)[*(ptr_to_i)] = sdup_str;
	(*ptr_to_i)++;
	return (1);
}

static char	**fill_array(char *s, char **array, char c)
{
	char	*end;
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
			if (!fill_with_dup(&array, s, end, &i))
				return (NULL);
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
