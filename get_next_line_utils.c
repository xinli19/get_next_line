#include "get_next_line.h"

int	get_return_index(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		else
			i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if(!str[i])
		return (0);
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(ft_strlen((char *)s) + 1);
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;	
	char	*s;

	i = 0;
	j = 0;
	k = 0;
	s = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (s == NULL)
		return (NULL);
	if (!s2[j])
	{
		while (s1[i])
			s[k++] = s1[i++];
	}
	while (s2[j])
	{
		while (s1[i])
			s[k++] = s1[i++];
		s[k++] = s2[j++];
	}
	s[k] = '\0';
	return (s);
}

int	is_returned(char	*s)
{
	int	i;
	
	i = 0;
	while(s[i])
	{
		if(s[i] == '\n')
			return(1);
		else
			i++;
	}
	return (0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xili <xili@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:29:54 by xili              #+#    #+#             */
/*   Updated: 2023/10/18 12:29:56 by xili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


