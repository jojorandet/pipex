/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:35 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/11 15:33:33 by jrandet          ###   ########.fr       */
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
# define BUFFER_SIZE 100

typedef struct s_pipex	t_pipex;

typedef union u_pipe
{
	int			fildes[2];
	struct
	{
		int		read;
		int		write;
	};
}				t_pipe;

typedef struct s_command
{
	char	**args;
	t_pipex	*pipex;
	pid_t	pid;
	t_pipe	*pipe_in;
	t_pipe	*pipe_out;
}			t_command;

typedef struct s_pipex
{
	int			fd_in;
	int			fd_out;
	char		**env;
	t_command	*cmds;
	t_pipe		*pipes;
	int			cmd_count;
	int			is_heredoc;
	char		*delimiter;
}				t_pipex;

char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_puterr(char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(char *s, size_t n);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*handle_empty_string(void);
void	*ft_calloc(size_t count, size_t size);
bool	ft_start_with(char *str, char *start);
void	clean_array(char **array);

void	struct_init(t_pipex *pipex, char **env);
void	handle_heredoc(t_pipex *pipex);
void	init_files(t_pipex *pipex, int argc, char **argv);
void	init_command_chain(t_pipex *pipex, int argc, char **argv);

void	execute_pipe(t_pipex *pipex);
char	*find_command_path(t_pipex *pipex, char *command);

void	handle_heredoc(t_pipex *pipex);
char	*get_line_from_stdin();

void	wait_for_children(t_pipex *pipex);
void	pipex_exit(t_pipex *pipex, char *error_msg);

#endif