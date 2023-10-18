/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:30:28 by xili              #+#    #+#             */
/*   Updated: 2023/10/18 12:30:29 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	get_return_index(char *str);
int	ft_strlen(char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int	is_returned(char *s);
int	set_line(char *src, char **line);
char	*set_next_temp(char *appended_str);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
int i_am_reading(int	fd, int byte_read, char **buffer, char **temp, char **appended_str);



#endif
