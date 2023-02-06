/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-jadd <mal-jadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:28:12 by mal-jadd          #+#    #+#             */
/*   Updated: 2023/02/06 00:37:56 by mal-jadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	s_len;

	if (!str)
		return (0);
	s_len = 0;
	while (str[s_len])
		s_len++;
	return (s_len);
}

char	*ft_get_line(char *fd_container)
{
	char	*result;
	size_t	cr_index;

	cr_index = 0;
	if (!fd_container || fd_container[cr_index] == 0)
		return (NULL);
	while (fd_container[cr_index] && fd_container[cr_index] != '\n')
		cr_index++;
	result = (char *)malloc(sizeof(char) * (cr_index + 2));
	cr_index = 0;
	while (fd_container[cr_index] && fd_container[cr_index] != '\n')
	{
		result[cr_index] = fd_container[cr_index];
		cr_index++;
	}
	if (fd_container[cr_index] == '\n')
	{
		result[cr_index] = '\n';
		cr_index++;
	}
	result[cr_index] = '\0';
	return (result);
}

char	*ft_trim(char *fd_container)
{
	char	*resutle;
	size_t	c_index;
	size_t	r_index;

	if (!fd_container)
		return (NULL);
	c_index = 0;
	while (fd_container[c_index] && fd_container[c_index] != '\n')
		c_index++;
	if (fd_container[c_index] == 0)
		return (free(fd_container), NULL);
	resutle = (char *)malloc(sizeof(char)
			* (1 + ft_strlen(fd_container) - c_index));
	c_index++;
	r_index = 0;
	while (fd_container[c_index])
	{
		resutle[r_index] = fd_container[c_index];
		r_index++;
		c_index++;
	}
	resutle[r_index] = '\0';
	return (free(fd_container), resutle);
}
