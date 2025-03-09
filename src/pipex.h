/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:35 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/09 11:25:20 by jrandet          ###   ########.fr       */
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
# include <stdbool.h>
# define BUFFERSIZE 100

typedef struct s_pipex	t_pipex;

typedef	union	u_pipe
{
	int			fildes[2];
	struct {
		int		read;
		int		write;
	};
}				t_pipe;

typedef	struct	s_command
{
	char	**args;
	t_pipex	*pipex;
	pid_t	pid;
	int		status;
	t_pipe	*pipe_out;
	t_pipe *pipe_in;
}				t_command;

typedef struct	s_pipex
{
	int			fd_in;
	int			fd_out;
	char		**env;
	t_command	*cmds;
	t_pipe		*pipes;
}				t_pipex;

bool	valid_arg(int argc, char **argv);


char	**ft_split(char *s, char c);
void	print_string_array(char **s);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);
char	*ft_strndup(char *s, size_t n);
char	*ft_strdup(char *s);
char	*handle_empty_string(void);
void	*ft_calloc(size_t count, size_t size);
bool	ft_start_with(char *str, char *start);
int		clean_array(char **array);

void	execute_pipe(t_pipex *pipex);
char	*find_command_path(t_pipex *pipex, char *command);

void	pipex_exit(t_pipex *pipex, char *error_msg);

#endif