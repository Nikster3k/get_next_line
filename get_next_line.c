/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:14 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/15 14:57:47 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_error(size_t size, char **str)
{
	if (size == (size_t)(-1))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static void	*buffer = NULL;
	char		*str;
	size_t		size;

	size = BUFFER_SIZE;
	if (buffer == NULL)
	{
		buffer = malloc(size);
		if (buffer == NULL)
			return (NULL);
		while (size--)
			((char *)buffer)[size] = 0;
	}
	str = read_file(fd, &buffer);
	return (str);
}
