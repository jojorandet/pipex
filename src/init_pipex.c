/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:58:30 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/10 21:59:04 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_command_string(t_pipex *pipex, t_command *cmd, char *str) //the command is split according to spaces 
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
		i = 3; // in the case where it is heredoc, 0 ./pipex 1 heredoc 2 DELIMITER 3 ncmd1 cmd2 outfile
	cmd = pipex->cmds;
	while (i < argc - 1)
	{
		split_command_string(pipex, cmd, argv[i]); //send the command to get split
		cmd++;
		i++;
	}
}

void	init_files(t_pipex *pipex, int argc, char **argv)
{
	if (!pipex->is_heredoc) // if the heredoc flag is not 1
	{
		pipex->fd_in = open(argv[1], O_RDONLY); //read the file and get the fd
		if (pipex->fd_in == -1)
			pipex_exit(pipex, "Error: Cannot access input file!\n");
	}
	pipex->fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (pipex->fd_out == -1)
	{
		close(pipex->fd_in); //close the fd in 
		pipex_exit(pipex, "Error: Cannot access output file!\n");
	}
}
