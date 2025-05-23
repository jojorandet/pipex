/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:14:49 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/11 15:34:47 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	char	*cursor;
	size_t	memory_needed;

	memory_needed = count * size;
	result = (char *)malloc(sizeof(char) * memory_needed);
	if (!result)
		return (NULL);
	cursor = result;
	while (memory_needed--)
		*(cursor++) = 0;
	return (result);
}
