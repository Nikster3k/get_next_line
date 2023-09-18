/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:18:16 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/18 19:47:04 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif //!BUFFER_SIZE

int		ft_strlen(char *s);
char	*get_next_line(int fd);
char	*read_file(int fd, void **buffer);
char	*ft_append_buffer(char *str, void *buffer, size_t index, size_t size);
void	ft_trim_buffer(char *buffer, size_t idx);
int		ft_check_error(int size, char **str);

#endif //!GET_NEXT_LINE_BONUS_H