/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:39:57 by anmendes          #+#    #+#             */
/*   Updated: 2025/04/05 16:26:11 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
#endif

char    *get_next_line(int fd)
{
    static char *buffer = NULL;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = read_file(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_line(buffer);
    if (!line)
        return (free(buffer), buffer = NULL, NULL);
    buffer = ft_next(buffer);
    return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (free(line), NULL);
	ft_strlcpy(line, buffer, i + 2);
	return (line);
}

char	*ft_next(char *buffer)
{
	char	*next;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	next = ft_strdup(buffer + i + 1);
	if (next == NULL)
		return (NULL);
	free(buffer);
	return (next);
}

char	*read_file(int fd, char *buffer)
{
	ssize_t	bytes_lidos;
	char	*cache;
	char	*temp;

	cache = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (cache == NULL)
		return (NULL);
	bytes_lidos = read(fd, cache, BUFFER_SIZE);
	while (bytes_lidos > 0)
	{
		cache[bytes_lidos] = '\0';
		temp = ft_strjoin(buffer, cache);
		if (temp == NULL)
			return (free(cache), free(buffer), NULL);
		free(buffer);
		buffer = temp;
		if (ft_strchr(cache, '\n'))
			break ;
		bytes_lidos = read(fd, cache, BUFFER_SIZE);
	}
	free(cache);
	if (bytes_lidos < 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
