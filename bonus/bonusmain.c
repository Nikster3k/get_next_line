/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:57:40 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/15 12:57:46 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int		fd = open("testfile", O_RDONLY);
	str = get_next_line(fd);
	printf("Line: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("Line: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("Line: %s", str);
	free(str);
	str = get_next_line(fd);
	printf("Line: %s", str);
	free(str);
	close(fd);
}