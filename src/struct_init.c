/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:51:09 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/10 11:53:09 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	struct_init(int argc, t_pipex *pipex, char **env)
{
	pipex->env = env;
	pipex->fd_in = -1;
	pipex->fd_out = -1;
	pipex->cmd_count = (argc - 3);
	pipex->cmds = NULL;
	pipex->pipes = NULL;
}
