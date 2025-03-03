/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:51:18 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/03 17:16:58 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	valid_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5)
		return(false);
	while (i < argc)
	{
		if (!argv[i])
			return (false);
		i++;
	}
	return (true);
}
