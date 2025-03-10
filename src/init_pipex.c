/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:58:30 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/10 16:52:51 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_command_string(t_pipex *pipex, t_command *cmd, char *str)
{
	cmd->args = ft_split(str, ' ');
	if (!cmd->args)
		pipex_exit(pipex, "Error: args could not be built!\n");
	cmd->pipex = pipex;
}

void	init_command_chain(t_pipex *pipex, int argc, char **argv)
{
	int			i;
	t_command	*cmd;

	i = 2;
    if (pipex->is_heredoc)
        i = 3;
	cmd = pipex->cmds;
	while (i < argc - 1)
	{
		split_command_string(pipex, cmd, argv[i]);
		cmd++;
		i++;
	}
}

void	init_files(t_pipex *pipex, int argc, char **argv)
{
	if (!pipex->is_heredoc)
    {
        pipex->fd_in = open(argv[1], O_RDONLY);
	    if (pipex->fd_in == -1)
		    pipex_exit(pipex, "Error: Cannot access input file!\n");
    }
	pipex->fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (pipex->fd_out == -1)
	{
		close(pipex->fd_in);
		pipex_exit(pipex, "Error: Cannot access output file!\n");
	}
}
