/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:14:37 by llopez-d          #+#    #+#             */
/*   Updated: 2020/01/23 20:59:07 by llopez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# define FD_SIZE 4096

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *s1);
char	*ft_strchr(char *s1, int c);
char	*ft_substr(char *s1, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif