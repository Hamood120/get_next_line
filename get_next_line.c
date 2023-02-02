/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-jadd <mal-jadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:41:54 by mal-jadd          #+#    #+#             */
/*   Updated: 2023/02/02 19:35:49 by mal-jadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char *str_buffer;
	char		*line;



	if (BUFFER_SIZE < 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);

	if( !fd || fd < 0 || fd >= 1000)
		return (NULL);
	str_buffer = read_fd(fd, str_buffer);
	if (*str_buffer == '\0')
		return (NULL);
	line = get_line(str_buffer);
	if (!line)
		return (NULL);
	str_buffer = buffer_trim(str_buffer);
	return (line);
}

/* int main()
{
	int fd = open("text.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	close(fd);
} */

