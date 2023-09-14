/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:20 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/14 19:03:35 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i])
		i++;
	return (i);
}

char	*ft_append_buffer(char *str, void *buffer, size_t index, size_t size)
{
	size_t	currsize;
	char	*newstr;
	size_t	i;

	if (index == size)
		return (str);
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
	while (i++ < n)
	{
		if (*buffer == '\n' || *buffer == '\0')
			return (i);
		buffer++;
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

char	*read_file(int fd, void *buffer)
{
	char	*str;
	size_t	asize;
	int		i;

	asize = BUFFER_SIZE;
	str = NULL;
	while (asize == BUFFER_SIZE)
	{
		if (!ft_strlen(buffer))
			asize = read(fd, buffer, BUFFER_SIZE);
		i = get_newline_idx(buffer, asize);
		str = ft_append_buffer(str, buffer, 0, i);
		ft_trim_buffer(buffer, i);
		if (i < BUFFER_SIZE)
			break ;
	}
	return (str);
}