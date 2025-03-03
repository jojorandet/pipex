/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:16 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/03 18:13:19 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_command_struct(t_command *cmd)
{
	if (cmd->path)
	{
		free(cmd->path);
		cmd->path = NULL;
	}
	if (cmd->args)
	{
		clean_array(cmd->args);
		cmd->args = NULL;
	}
}

void	pipex_exit(t_pipex *pipex, char *error_msg)
{
	free_command_struct(&pipex->cmd1);
	free_command_struct(&pipex->cmd2);
	if (error_msg)
	{
		ft_putstr(error_msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
