/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:19:58 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/26 18:41:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int  ft_count_words(char *s, char c)
{
	int count_words;

	while (*s && *s == c)
		s++;
	while (*s)
	{
		while(*s && *s == c)
			s++;
		if (*s != c)
			count_words++;
		while (*s && *s != c)
			s++;
	}
	return (count_words);
}

void	ft_split(char *s, char c)
{
	int count_words;
	
	if (!s || s[0] == '\0')
		return ;
	count_words = ft_count_words(s, c);
	printf("number of words %d\n", count_words);
	return ;
}