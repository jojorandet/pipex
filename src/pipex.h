/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:19:35 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/26 16:23:24 by jrandet          ###   ########.fr       */
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

typedef struct s_process_info
{
	int	pid;
	int	status;
}				t_process_info;

typedef union u_pipe_fd
{
	int	file_des_table[2];
	struct
	{
		int	in;
		int	out;
	};
}				t_pipe_fd;

int	ft_parsing(int argc, char **argv);

#endif