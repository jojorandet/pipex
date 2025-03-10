/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/10 17:01:49 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

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
		write(2, "Invalid input! filein cmd1 cmd2 fileout\n", 41);
		exit(EXIT_FAILURE);
	}
	struct_init(argc, &pipex, env);
	if (ft_strcmp(argv[1],"here_doc") == 0)
	{
		if (argc < 6)
		{
			write(1, "Invalid synthax for here_doc: here_doc DELIMITER cmd1 cmd2 outfile\n", 68);
			exit(EXIT_FAILURE);
		}
		pipex.is_heredoc = 1;
		handle_heredoc(argc, argv, env);
		pipex.cmd_count = argc - 4;
	}
	else
	{
		pipex.is_heredoc = 0;
		pipex.cmd_count = argc - 3;
	}
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
