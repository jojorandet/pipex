/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:40:23 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/10 18:40:21 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_next_line_pos(char *buffer, char c)
{
	int	pos;
	
	if (!buffer)
		return (0);
	pos = 0;
	while (*buffer)
	{
		if (*buffer == c)
			return (pos);
		pos++;
		buffer++;
	}
	return (-1);
}

static char *get_line_from_stdin(char **line)
{
	
}

static void    get_line_into_pipe(t_pipex *pipex)
{
	char		*line;
	static char	*remainder = NULL;
	char		*new_line;

	close(pipex->pipes->read);
	while (1)
	{
		line = get_line_from_stdin(&line);
		if (!line)
			break ;
		// if i find the new line at the end of the line, i need to append it to \0 to 
		
		if (ft_strcmp(line, pipex->delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(pipex->pipes->write, line, ft_strlen(line));
		write(pipex->pipes->write, "\n", 1);
	}
}

void    here_doc_handler(t_pipex *pipex)
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
	{
		get_line_into_pipe(pipex);
	}
	if (pid != 0)
	{
		close(pipex->pipes->write);
		pipex->fd_in = pipex->pipes->read;
		wait(NULL);
	}
	
}
