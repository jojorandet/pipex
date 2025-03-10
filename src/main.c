/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/09 21:58:13 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

static void	split_command_string(t_pipex *pipex, t_command *cmd, char *str)
{
	cmd->args = ft_split(str, ' ');
	if (!cmd->args)
		pipex_exit(pipex, "Error: args could not be built!\n");
	cmd->pipex = pipex;
}

static void	init_command_chain(t_pipex *pipex, int argc, char **argv)
{
	int			i;
	t_command	*cmd;

	i = 2;
	cmd = pipex->cmds;
	while (i < argc - 1)
	{
		split_command_string(pipex, cmd, argv[i]);
		cmd++;
		i++;
	}
}

static void	init_files(t_pipex *pipex, int argc, char **argv)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
		pipex_exit(pipex, "Error: Cannot access input file!\n");
	pipex->fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (pipex->fd_out == -1)
	{
		close(pipex->fd_in);
		pipex_exit(pipex, "Error: Cannot access output file!\n");
	}
}

static bool	valid_arg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5)
		return (false);
	while (i < argc)
	{
		if (!argv[i])
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (!valid_arg(argc, argv))
	{
		write(2, "Invalid input! filein cmd1 | cmd2 fileout\n", 43);
		exit(EXIT_FAILURE);
	}
	pipex.env = env;
	pipex.fd_in = -1;
	pipex.fd_out = -1;
	pipex.cmd_count = (argc - 3);
	pipex.cmds = NULL;
	pipex.pipes = NULL;
	init_files(&pipex, argc, argv);
	pipex.cmds = ft_calloc((argc - 2), sizeof(*(pipex.cmds)));
	if (!pipex.cmds)
		return (pipex_exit(&pipex, "Malloc error!\n"), 1);
	pipex.pipes = ft_calloc((argc - 3), sizeof(*(pipex.pipes)));
	if (!pipex.pipes)
		return (pipex_exit(&pipex, "Malloc error!\n"), 1);
	init_command_chain(&pipex, argc, argv);
	execute_pipe(&pipex);
	wait_for_children(&pipex);
	pipex_exit(&pipex, NULL);
	return (0);
}
