/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:20 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/15 16:16:45 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_append_buffer(char *str, void *buffer, size_t index, size_t size)
{
	size_t	currsize;
	char	*newstr;
	size_t	i;

	if (size > BUFFER_SIZE)
		size = BUFFER_SIZE;
	currsize = 0;
	while (str != NULL && str[currsize])
		currsize++;
	newstr = malloc(currsize + (size - index) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < (size - index) + currsize)
	{
		if (i < currsize)
			newstr[i] = str[i];
		else
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
		if (buffer[i] == '\n')
			return (i);
		if (buffer[i] == '\0')
			break ;
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
		if (((char *)*buffer)[0] == 0)
			asize = read(fd, *buffer, BUFFER_SIZE);
		if (ft_check_error(asize, &str))
			break ;
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
