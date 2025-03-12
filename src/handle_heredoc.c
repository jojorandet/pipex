/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:40:23 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/12 14:43:07 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_line_into_pipe(t_pipex *pipex)
{
	char		*line;
	int			i;

	while (1)
	{
		line = get_line_from_stdin();
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		line[i] = '\0';
		if (line[0] != 0 && ft_strcmp(line, pipex->delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(pipex->pipes[0].write, line, ft_strlen(line));
		write(pipex->pipes[0].write, "\n", 1);
		free(line);
	}
}

void	handle_heredoc(t_pipex *pipex)
{
	if (pipe(pipex->pipes->fildes) == -1)
		pipex_exit(pipex, "Pipe creation failed\n");
	get_line_into_pipe(pipex);
	close(pipex->pipes[0].write);
	if (dup2(pipex->pipes[0].read, STDIN_FILENO) == -1)
		pipex_exit(pipex, "Dup2 failed in heredoc\n");
	close(pipex->pipes[0].read);
}
