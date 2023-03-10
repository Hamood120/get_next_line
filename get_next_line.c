/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-jadd <mal-jadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:41:54 by mal-jadd          #+#    #+#             */
/*   Updated: 2023/02/06 07:41:46 by mal-jadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*fd_container;
	char		*fd_line;

	if (fd < 0 || fd > 4096 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	fd_container = read_fd(fd, fd_container);
	fd_line = ft_get_line(fd_container);
	fd_container = ft_trim(fd_container);
	return (fd_line);
}

char	*read_fd(int fd, char *fd_container)
{
	char	*buffer;
	int		r_byte;

	if (! fd_container)
	{
		fd_container = (char *)malloc(1);
		*fd_container = '\0';
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r_byte = 1;
	while (r_byte > 0 && !ft_strchr(fd_container, '\n'))
	{
		r_byte = read(fd, buffer, BUFFER_SIZE);
		if (r_byte < 0)
			return (free(buffer), NULL);
		buffer[r_byte] = '\0';
		fd_container = ft_strjoin(fd_container, buffer);
	}
	return (free(buffer), fd_container);
}

char	*ft_strchr(const char *str, int c)
{
	int		s_index;

	if (!str || !c)
		return (NULL);
	s_index = 0;
	while (str[s_index] && str[s_index] != c)
		s_index++;
	if (str[s_index] == c)
		return ((char *)str + s_index);
	return (NULL);
}

char	*ft_strjoin(char *fd_container, char *buffer)
{
	char	*result;
	size_t	cb_index;
	size_t	r_index;

	if (!buffer)
		return (fd_container);
	result = (char *)malloc(sizeof(char)
			* (ft_strlen(fd_container) + ft_strlen(buffer) + 1));
	cb_index = 0;
	r_index = 0;
	while (fd_container[cb_index])
	{
		result[r_index] = fd_container[cb_index];
		r_index++;
		cb_index++;
	}
	cb_index = 0;
	while (buffer[cb_index])
	{
		result[r_index] = buffer[cb_index];
		r_index++;
		cb_index++;
	}
	result[r_index] = '\0';
	return (free(fd_container), result);
}

/* int main(void)
{
	char	*line;
	int		fd = open("text.txt", O_RDONLY);
	int		a = 20;

	while (a > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		a--;
	}
	close(fd);
	return 0;
}
 */
