/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:35 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/26 18:36:18 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

# define BUFFERSIZE 100

typedef union u_pipe_ends
{
	int	fd_array[2];
	struct
	{
		int	in;
		int	out;
	};
}				t_pipe_ends;

typedef struct s_pipex
{
	int			pid;
	int			status;
	t_pipe_ends	connect;
}				t_pipex;

int		main(int argc, char **argv, char **env);
int		ft_parsing(int argc, char **argv);
void    set_pid(char **argv, char **env);
void	error_display(t_pipex *pipex, char *error_msg);
void    ft_split(char *s, char c);

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);

#endif