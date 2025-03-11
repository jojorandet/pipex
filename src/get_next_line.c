/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:52:51 by jrandet           #+#    #+#             */
/*   Updated: 2025/03/11 10:35:47 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_stash(char *stash)
{
    if (!stash)
        return ;
    free(stash);
    stash = NULL;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

char    *read_from_stdin(char *stash)
{
    char        buffer[BUFFER_SIZE + 1];
    size_t      count_bytes;
    char        *temp;



}

char    *get_line_from_stdin(void)
{
    static char *stash= NULL;
    char *line;
    
    if (read(STDIN_FILENO, 0, 0) < 0 || BUFFER_SIZE < 0)
        return (NULL);
    if (!stash)
    {
        stash = ft_strdup("");
        if (!stash)
            return (NULL);
    }
    stash = read_from_stdin(stash);
    if (!stash || !*stash)
    {
        free_stash(stash);
        return (NULL);
    }

    
	
}
