/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:16 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/12 14:31:34 by jrandet          ###   ########.fr       */
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

static void	free_commands(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		free_command_struct(&pipex->cmds[i]);
		i++;
	}
}

void	pipex_exit(t_pipex *pipex, char *error_msg)
{
	if (pipex->cmds)
	{
		free_commands(pipex);
		free(pipex->cmds);
		pipex->cmds = NULL;
	}
	if (pipex->pipes)
	{
		free(pipex->pipes);
		pipex->pipes = NULL;
	}
	if (pipex->fd_in != -1)
		close(pipex->fd_in);
	if (pipex->fd_out != -1)
		close(pipex->fd_out);
	if (error_msg)
	{
		ft_puterr(error_msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	wait_for_children(t_pipex *pipex)
{
	int	status;
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
		waitpid(pipex->cmds[i++].pid, &status, 0);
}
