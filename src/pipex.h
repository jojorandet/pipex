/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:35 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/02 16:37:34 by jrandet          ###   ########.fr       */
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

typedef struct s_pipex
{
	int			pid;
	int			pipefd[2];
}				t_pipex;

int		main(int argc, char **argv, char **env);
int		ft_parsing(int argc, char **argv);
void	get_pid(char **argv, char **env);
void	error_display(t_pipex *pipex, char *error_msg);

char	**ft_split(char *s, char c);
void	print_string_array(char **s);

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
size_t	ft_strlen(char *s);
char	*ft_strndup(char *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
bool	ft_start_with(char *str, char *start);

void	redirect_child_process(t_pipex *pipex, char **argv);
void	redirect_parent_process(t_pipex *pipex, char **argv);

void	execute_command(char *argv, char **env);

#endif