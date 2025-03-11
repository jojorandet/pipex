/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:40:23 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/11 15:32:13 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_line_into_pipe(t_pipex *pipex)
{
	char		*line;
	int			i;

	close(pipex->pipes->read);
	while (1)
	{
		line = get_line_from_stdin();
		if (!line)
			break ;
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		line[i] = '\0';
		if (ft_strcmp(line, pipex->delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(pipex->pipes->write, line, ft_strlen(line));
		write(pipex->pipes->write, "\n", 1);
		free(line);
	}
	close(pipex->pipes->write);
}

void	handle_heredoc(t_pipex *pipex)
{
	int pid;
	
	pipe(pipex->pipes->fildes);
	pid = fork();
	if (pid == -1)
	{
		pipex_exit(pipex, "Creating child in heredoc failed\n");
		return ;
	}
	if (pid == 0)
		get_line_into_pipe(pipex);
	if (pid != 0)
	{
		close(pipex->pipes->write);
		pipex->fd_in = pipex->pipes->read;
		wait(NULL);
	}
}
