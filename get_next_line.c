/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:29:10 by xili              #+#    #+#             */
/*   Updated: 2023/10/18 13:23:27 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int set_line(char *src, char **line)
{
	int	i;
	int	j;

	i = 0;
	j = get_return_index(src);
	*line = malloc(j + 2);
	if (*line == NULL)
		return (1); 
	while(i <= j)
	{
		(*line)[i] = src[i];
		i++;
	}
	(*line)[i] = '\0';
	return (0);
}

char	*set_next_temp(char *appended_str)
{
	int i;
	int j;
	char *temp;
	
	i = 0;
	j = get_return_index(appended_str);
	j++;
	if ((ft_strlen(appended_str) - j + 2) < 0)
		return (NULL);
	temp = malloc(ft_strlen(appended_str) - j + 2);
	if (temp == NULL)
		return (NULL);
	while(appended_str[j])
	{
		temp[i] = appended_str[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	free(appended_str);
	return (temp);
}	

int is_ended(char *str)
{
	while(*str)
		str++;
	if(*str == '\0')
		return (1);
	return (0);
}
int reading(int	fd, int byte_read, char **buffer, char **temp, char **appended_str)
{
	while(byte_read != -1)
	{
		*buffer = malloc(BUFFER_SIZE + 1);
		if (*buffer == NULL)
			return (1);
		byte_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[byte_read] = '\0';
		if (**buffer == '\0')
				break;
		if (!*temp)
		{
			*temp = malloc(1);
			if (*temp == NULL)
				return (1);
			*temp[0] = '\0';
		}
		*appended_str = ft_strjoin(*temp, *buffer);
		if (*appended_str == NULL)
			return (1);
		*temp = ft_strdup(*appended_str);
		if (*temp == NULL)
			return (1);
		//printf("appended str is %s \n",temp);
		if (is_returned(*temp) == 1)
			break;
	}
	return (0);
}
char	*get_next_line(int	fd)
{
	char		*buffer;
	int		byte_read;
	static char	*temp;
 	char	*appended_str;
	char	*line;

	if (BUFFER_SIZE == 0 || fd < 0 )
		return (NULL);
	byte_read = 1;
	if (reading(fd, byte_read, &buffer, &temp, &appended_str) == 1)
		return (NULL);
	if (temp == NULL)
		return (NULL);
	if(is_returned(temp) == 0)
		return (NULL);
	if (set_line(temp, &line) == 1)
		return (NULL);
	if (is_returned(temp) == 1)
	{
		temp = set_next_temp(temp);
		if (temp == NULL)
			return (NULL);
	}
	else
		return (NULL);
	free(buffer);
	return(line);
}


int	main()
{
	int	fd;

	fd = open("12-bigben.txt",O_RDONLY);
	printf("result:%s",get_next_line(fd));
	printf("\n________1__________________\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________2_________________\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________3___________--\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________4___________--\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________5___________--\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________6___________--\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________7___________--\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________8___________--\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________9__________--\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________10___________--\n");
	printf("result:%s",get_next_line(fd));
	printf("\n________11__________--\n");
	printf("result:%s",get_next_line(fd));

return (0);
}

