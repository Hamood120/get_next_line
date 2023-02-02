/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-jadd <mal-jadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:35:06 by mal-jadd          #+#    #+#             */
/*   Updated: 2023/02/02 18:39:32 by mal-jadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef	BUFFER_SIZE
# define	BUFFER_SIZE 1

#endif

char	*get_next_line(int fd);
char	*read_fd(int fd, char *buffer);
char	*ft_strjoin(char *dest, char *src);
int	ft_strlen(char *s);
char	*get_line(char *s);
char	*buffer_trim(char *buffer);
#endif
