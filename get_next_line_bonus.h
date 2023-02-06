/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-jadd <mal-jadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:28:18 by mal-jadd          #+#    #+#             */
/*   Updated: 2023/02/06 01:53:11 by mal-jadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_fd(int fd, char *fd_container);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *fd_container, char *buffer);
size_t	ft_strlen(const char *str);
char	*ft_get_line(char *fd_container);
char	*ft_trim(char *fd_container);

#endif
