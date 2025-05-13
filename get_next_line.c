/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:06:09 by jaeklee           #+#    #+#             */
/*   Updated: 2025/05/13 16:17:44 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line;
    char buffer[BUFFER_SIZE + 1];
    char *new_line;
    int read_bytes;
    static char *remember; 
    char *temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!remember)
        remember = ft_strjoin("", 0);
    while (!ft_strchr(remember, '\n'))
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes <= 0)
            break;
        buffer[read_bytes] = '\0';
        temp = ft_strjoin(remember, buffer);
        if (!temp)
            return (NULL);
        free(remember);
        remember = temp;
    }
    if (!remember || *remember == '\0')
    {
        free(remember);
        remember = NULL;
        return (NULL);
    }
    new_line = ft_strchr(remember, '\n');
    if (new_line)
    {
        int len = (new_line - remember) + 1;
        line = ft_substr(remember, 0, len);
    }
    else
        line = ft_strdup(remember);
    
    if (!line)
        return (NULL);
        
    if (new_line && *(new_line + 1) != '\0')
    {
        temp = ft_strdup(new_line + 1);
       
        remember = temp;
    }
    else
        remember = NULL;
    return (line);
}