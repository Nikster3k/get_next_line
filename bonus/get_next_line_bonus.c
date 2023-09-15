/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:14 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/15 12:57:05 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_new_list_buffer(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (new);
	new->fd = fd;
	new->buffer = malloc(BUFFER_SIZE);
	if (new->buffer == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *list;
	*list = new;
}

void	*ft_get_fd_buffer(t_list **buffers, int fd)
{
	t_list	*current;

	current = *buffers;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current->buffer);
		current = current->next;
	}
	current = ft_new_list_buffer(fd);
	ft_lstadd_front(buffers, current);
	return (current->buffer);
}

char	*get_next_line(int fd)
{
	static t_list	*buffers = NULL;
	void			*currbuffer;
	char			*str;

	currbuffer = ft_get_fd_buffer(&buffers, fd);
	str = read_file(fd, &currbuffer);
	return (str);
}
