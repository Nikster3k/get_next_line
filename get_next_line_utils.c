/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:20 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/15 12:15:32 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_append_buffer(char *str, void *buffer, size_t index, size_t size)
{
	size_t	currsize;
	char	*newstr;
	size_t	i;

	if (size > BUFFER_SIZE)
		size = BUFFER_SIZE;
	currsize = ft_strlen(str);
	newstr = malloc(currsize + (size - index) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < currsize)
	{
		newstr[i] = str[i];
		i++;
	}
	while (i < (size - index) + currsize)
	{
		newstr[i] = ((char *)buffer)[index + i - currsize];
		i++;
	}
	newstr[i] = '\0';
	free(str);
	return (newstr);
}

int	get_newline_idx(char *buffer, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return (n);
}

void	ft_trim_buffer(char *buffer, size_t idx)
{
	int	x;

	x = 0;
	while (idx < BUFFER_SIZE)
		buffer[x++] = buffer[idx++];
	while (x < BUFFER_SIZE)
		buffer[x++] = 0;
}

char	*read_file(int fd, void **buffer)
{
	char	*str;
	size_t	asize;
	int		i;

	asize = BUFFER_SIZE;
	str = NULL;
	while (asize == BUFFER_SIZE)
	{
		if (!ft_strlen(*buffer))
			asize = read(fd, *buffer, BUFFER_SIZE);
		if (asize == 0)
			break ;
		i = get_newline_idx(*buffer, asize);
		str = ft_append_buffer(str, *buffer, 0, i + 1);
		ft_trim_buffer(*buffer, i + 1);
		if (i < BUFFER_SIZE)
			return (str);
	}
	free(*buffer);
	*buffer = NULL;
	return (str);
}
