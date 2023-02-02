/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-jadd <mal-jadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:41:51 by mal-jadd          #+#    #+#             */
/*   Updated: 2023/02/02 18:45:31 by mal-jadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*result;
	int		len;

	result = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	if (!result)
		return (NULL);
	len = 0;
	while (*dest)
	{
		result[len] = *dest;
		dest++;
		len++;
	}
	while (*src)
	{
		result[len] = *src;
		src++;
		len++;
	}
	result[len] = '\0';
	return (free(result), result);
}

char	*ft_strchr(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	if(s[len] == c)
		return (s + len);
	return (0);
}


//this function read amunt of buffer_size from fd to reach new line or null
//	it is return a string
char	*read_fd(int fd, char *buffer)
{
	char	*r_buffer;
	int		r_byte;

	if (!buffer)
	{
		buffer = malloc(1);
		*buffer = '\0';
	}
	r_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!r_buffer)
		return (NULL);
	r_byte = 1;
	while (!ft_strchr(buffer, '\n') && r_byte != 0)
	{
		r_byte = read (fd, r_buffer, BUFFER_SIZE);
		if (r_byte == -1)
		{
			free(r_buffer);
			return (NULL);
		}
		r_buffer[r_byte] = '\0';
		buffer = ft_strjoin(buffer, r_buffer);
	}
	return (buffer);
}

char	*get_line(char *s)
{
	char	*line;
	int		len;

	line = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (s[len] != '\n' && s[len])
	{
		line[len] = s[len];
		len++;
	}
	line[len] =  '\0';
	return (line);
}


char	*buffer_trim(char *buffer)
{
	char	*result;
	int		len;
	result = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!result)
		return (NULL);
	len = 0;
	while (*buffer != '\n' && *buffer)
		buffer++;
	if (*buffer)
		return (NULL);
	else
		buffer++;
	while(buffer[len])
	{
		result[len] =  buffer[len];
		len++;
	}
	result[len] = '\0';
	return (result);
}

