/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:16 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/14 18:51:20 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif //!BUFFER_SIZE

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*read_file(int fd, void *buffer);
char	*ft_append_buffer(char *str, void *buffer, size_t index, size_t size);
void	ft_trim_buffer(char *buffer, size_t idx);

#endif //!GET_NEXT_LINE_H