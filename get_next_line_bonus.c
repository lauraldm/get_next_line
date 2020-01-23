/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:14:27 by llopez-d          #+#    #+#             */
/*   Updated: 2020/01/23 21:05:58 by llopez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	write_in_line(char **read_line, char **line)
{
	size_t	len;
	char	*aux;

	len = 0;
	while ((*read_line)[len] != '\0' && (*read_line)[len] != '\n')
		len++;
	if ((*read_line)[len] == '\n')
	{
		*line = ft_substr(*read_line, 0, len);
		aux = ft_strdup(*read_line + len + 1);
		free(*read_line);
		*read_line = aux;
	}
	else
	{
		*line = ft_strdup(*read_line);
		free(*read_line);
		*read_line = NULL;
		return (0);
	}
	return (1);
}

int	returns(int fd, int n_bytes, char **read_line, char **line)
{
	if (n_bytes < 0 || fd < 0)
		return (-1);
	else if (n_bytes == 0 && read_line[fd] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (write_in_line(&read_line[fd], line));
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			n_bytes;
	static char	*read_line[FD_SIZE];
	char		*aux;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((n_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[n_bytes] = '\0';
		if (read_line[fd] == NULL)
			read_line[fd] = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(read_line[fd], buff);
			free(read_line[fd]);
			read_line[fd] = aux;
		}
		if (ft_strchr(read_line[fd], '\n'))
			break ;
	}
	return (returns(fd, n_bytes, read_line, line));
}
