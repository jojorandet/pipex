/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:51:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/26 16:17:32 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parsing(int argc, char **argv)
{
	int	i;
	int	return_val;

	i = 0;
	return_val = 1;
	if (argc != 5)
	{
		return_val = 0;
		return (return_val);
	}
	while (argv[i])
	{
		if (!argv[i] || !ft_strcmp(argv[i], " "))
		{
			return_val = 0;
			break ;
		}
		i++;
	}
	return (return_val);
}
