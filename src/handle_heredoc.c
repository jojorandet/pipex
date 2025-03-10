/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:40:23 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/10 22:29:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_line_into_pipe(t_pipex *pipex)
{
	char		*line;
	static char	*remainder = NULL;
	char		*new_line;

	close(pipex->pipes->read);
	while (1)
	{
		line = get_line_from_stdin(); // what do i get in return? i get a line with a new line at the end 
		if (!line)
			break ;
		while (*line != '\n')
			line++;
		*line = '\0';
		if (ft_strcmp(line, pipex->delimiter) == 0) // i need to compare to something so i need to have a null terminator 
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
