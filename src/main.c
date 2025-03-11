/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/11 15:44:53 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_cmd_count(int argc, char **argv, t_pipex *pipex)
{
	if (ft_strcmp(argv[1],"here_doc") == 0)
	{
		if (argc < 6)
		{
			write(1, "Invalid synthax for here_doc: here_doc DELIMITER cmd1 cmd2 outfile\n", 68);
			exit(EXIT_FAILURE);
		}
		pipex->is_heredoc = 1;
		handle_heredoc(pipex);
		pipex->cmd_count = argc - 4;
	}
	else
	{
		pipex->is_heredoc = 0;
		pipex->cmd_count = argc - 3;
	}
}

void	create_arrays(int argc, t_pipex *pipex)
{
	pipex->cmds = ft_calloc((argc - 2), sizeof(*(pipex->cmds)));
	if (!pipex->cmds)
		(pipex_exit(pipex, "Malloc error!\n"));
	pipex->pipes = ft_calloc((argc - 3), sizeof(*(pipex->pipes)));
	if (!pipex->pipes)
		(pipex_exit(pipex, "Malloc error!\n"));
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
		write(2, "Invalid input! filein cmd1 cmd2 fileout\n", 41);
		exit(EXIT_FAILURE);
	}
	struct_init(&pipex, env);
	get_cmd_count(argc, argv, &pipex);
	init_files(&pipex, argc, argv);
	create_arrays(argc, &pipex);
	init_command_chain(&pipex, argc, argv);
	execute_pipe(&pipex);
	wait_for_children(&pipex);
	pipex_exit(&pipex, NULL);
}
