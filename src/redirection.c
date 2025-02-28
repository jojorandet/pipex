/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:42:15 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/28 11:54:56 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_child_process(t_pipex *pipex, char **argv)
{
	int	fd_in;

	fd_in = open(argv[1],  )
}