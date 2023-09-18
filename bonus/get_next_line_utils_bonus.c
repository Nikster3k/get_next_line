/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:20 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/18 19:47:38 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_check_error(int size, char **str)
{
	if (size == -1)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

char	*ft_append_buffer(char *str, void *buffer, size_t size, size_t buffsize)
{
	size_t	currsize;
	char	*newstr;
	size_t	i;

	if (size > buffsize)
		size = buffsize;
	currsize = ft_strlen(str);
	buffsize = ft_strlen(buffer);
	if (size > buffsize)
		size = buffsize;
	newstr = malloc(currsize + size + 1);
	if (newstr == NULL)
		return (free(str), NULL);
	i = 0;
	while (i < size + currsize)
	{
		if (i < currsize)
			newstr[i] = str[i];
		else
			newstr[i] = ((char *)buffer)[i - currsize];
		i++;
	}
	newstr[i] = '\0';
	return (free(str), newstr);
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
	int		asize;
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
		str = ft_append_buffer(str, *buffer, i + 1, asize);
		if (str == NULL)
			break ;
		ft_trim_buffer(*buffer, i + 1);
		if (i < asize)
			return (str);
	}
	free(*buffer);
	*buffer = NULL;
	return (str);
}
