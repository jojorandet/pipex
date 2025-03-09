/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:16 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/09 11:27:52 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_command_struct(t_command *cmd)
{
	if (cmd->args)
	{
		clean_array(cmd->args);
		cmd->args = NULL;
	}
}

static void	free_commands(t_command *cmds)
{
	while (cmds->args != NULL)
	{
		free_command_struct(cmds);
		cmds++;
	}
}

void	pipex_exit(t_pipex *pipex, char *error_msg)
{
	free_commands(pipex->cmds);
	free(pipex->cmds);
	pipex->cmds = NULL;
	free(pipex->pipes);
	pipex->pipes = NULL;
	close(pipex->fd_in);
	close(pipex->fd_out);
	if (error_msg)
	{
		ft_putstr(error_msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
