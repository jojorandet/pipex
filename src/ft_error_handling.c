/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:16 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/26 17:52:22 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_display(t_pipex *pipex, char *error_msg)
{
	//close_and_free(pipex);
	(void)pipex;
	if (error_msg)
	{
		ft_putstr(error_msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
