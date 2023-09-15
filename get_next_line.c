/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:14 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/15 11:48:02 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
