/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:59 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/11 16:45:27 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_arrays(t_pipex *pipex)
{
	pipex->cmds = ft_calloc((pipex->cmd_count + 1), sizeof(*(pipex->cmds)));
	if (!pipex->cmds)
		(pipex_exit(pipex, "Malloc error!\n"));
	pipex->pipes = ft_calloc((pipex->cmd_count), sizeof(*(pipex->pipes)));
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

void	assign_heredoc_flag(t_pipex *pipex, int argc, char **argv)
{
	if (ft_strcmp(argv[1],"here_doc") == 0)
	{
		if (argc < 6)
		{
			write(1, "Invalid synthax for here_doc.\n", 31);
			exit(EXIT_FAILURE);
		}
		pipex->is_heredoc = 1;
	}
	else 
	{
		pipex->is_heredoc = 0;
	}
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
	assign_heredoc_flag(&pipex, argc, argv);
	if (pipex.is_heredoc)
	{
		pipex.cmd_count = argc - 4;
		pipex.delimiter = argv[2];
	}
	else
		pipex.cmd_count = argc - 3;
	
	create_arrays(&pipex);
	init_files(&pipex, argc, argv);
	if (pipex.is_heredoc)
		handle_heredoc(&pipex);
	init_command_chain(&pipex, argc, argv);
	execute_pipe(&pipex);
	wait_for_children(&pipex);
	pipex_exit(&pipex, NULL);
}
