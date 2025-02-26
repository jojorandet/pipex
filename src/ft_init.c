/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:47:44 by jrandet           #+#    #+#             */
/*   Updated: 2025/02/26 18:39:38 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    set_pid(char **argv, char **env)
{
    t_pipex pipex;
    (void)env;
    (void)argv;

    if (pipe(pipex.connect.fd_array) == -1)
        error_display(&pipex, "Pipe could not be created\n");
    pipex.pid = fork();
    if (pipex.pid == -1)
        error_display(&pipex, "Child process could not be created\n");
    if (pipex.pid == 0)
    {
        //redirect_child(pipex, argv[1]);
        //execute_cmd(argv[2], env);
    }

    return ;
}