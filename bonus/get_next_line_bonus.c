/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:14 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/15 17:00:28 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_new_list_buffer(int fd)
{
	t_list	*new;
	size_t	size;
	
	size = BUFFER_SIZE;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (new);
	new->fd = fd;
	new->buffer = malloc(size);
	if (new->buffer == NULL)
		return (NULL);
	while (size--)
		((char *)new->buffer)[size] = 0;
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

void	ft_clremptylst_item(t_list	**node)
{
	t_list	*curr;
	t_list	*prev;

	prev = NULL;
	curr = *node;
	while (curr != NULL)
	{
		if (curr->buffer == NULL)
		{
			if (prev == NULL)
			{
				*node = curr->next;
				free(curr);
				curr = *node;
				continue ;
			}
			prev->next = curr->next;
			free(curr);
			curr = prev->next;
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*buffers = NULL;
	void			*currbuffer;
	char			*str;

	currbuffer = ft_get_fd_buffer(&buffers, fd);
	str = read_file(fd, &currbuffer);
	ft_clremptylst_item(&buffers);
	return (str);
}
