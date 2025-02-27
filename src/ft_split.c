/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:19:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/27 17:18:54 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count_words(char *s, char c)
{
	int	count_words;

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

static int	clean_array(char **array)
{
	int	i;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static char	**fill_array(char *s, char ***array, char c)
{
	char	*end;
	char	*sdup_str;
	size_t	i;

	while (*s)
	{
		while (*s == 'c')
			s++;
		end = s;
		while (*end && *end != c)
			end++;
		if (s != end)
		{
			sdup_str = ft_strndup(s, end - s);
			if (!sdup_str)
				clean_array(array);
			*array[i] = sdup_str;
			i++;
		}
		s = end;
	}
	array[i] = '\0';
	return (array);
}

char	**ft_split(char *s, char c)
{
	int		count_words;
	char	**split_array;

	if (!s || s[0] == '\0')
		return ;
	count_words = ft_count_words(s, c);
	if (count_words < 0)
		return (ft_calloc(1, sizeof(char *)));
	split_array = (char **)malloc(sizeof(*split_array) * (count_words + 1));
	if (!split_array)
		return (NULL);
	if (fill_array(s, &split_array, c) == NULL)
		return (NULL);
	return (split_array);
}
