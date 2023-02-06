/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-jadd <mal-jadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:26:06 by mal-jadd          #+#    #+#             */
/*   Updated: 2023/02/06 07:47:15 by mal-jadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <fcntl.h>
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*fd_container[1024];
	char		*fd_line;

	if (fd < 0 || fd > 4096 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	fd_container[fd] = read_fd(fd, fd_container[fd]);
	fd_line = ft_get_line(fd_container[fd]);
	fd_container[fd] = ft_trim(fd_container[fd]);
	return (fd_line);
}

char	*read_fd(int fd, char *fd_container)
{
	char	*buffer;
	int		r_byte;

	if (!fd_container)
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
	int	s_index;

	if (!str || !c)
		return (0);
	s_index = 0;
	while (str[s_index] && str[s_index] != c)
		s_index++;
	if (str[s_index] == c)
		return ((char *)str + s_index);
	return (0);
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
	char	*line_1, *line_2, *line_3;
	int		fd_1 = open("text1.txt", O_RDONLY);
	int		fd_2 = open("text2.txt", O_RDONLY);
	int		fd_3 = open("text3.txt", O_RDONLY);
	int		a = 3;

	while (a > 0)
	{
		line_1 = get_next_line(fd_1);
		line_2 = get_next_line(fd_2);
		line_3 = get_next_line(fd_3);
		printf("fd_1[%s]", line_1);
		printf("fd_2[%s]", line_2);
		printf("fd_3[%s]", line_3);
		free(line_1);
		free(line_2);
		free(line_3);
		a--;
	}
	close(fd_1);
	close(fd_2);
	close(fd_3);
	return 0;
} */
