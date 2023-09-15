/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsassenb <nsassenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:57:40 by nsassenb          #+#    #+#             */
/*   Updated: 2023/09/15 16:56:30 by nsassenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int	file1 = open("testfile1", O_RDONLY);
	int	file2 = open("testfile2", O_RDONLY);
	str = get_next_line(file1);
	printf("File1: %s", str);
	free(str);
	str = get_next_line(file2);
	printf("File2: %s", str);
	free(str);
	str = get_next_line(file1);
	printf("File1: %s", str);
	free(str);
	str = get_next_line(file2);
	printf("File2: %s", str);
	free(str);
	str = get_next_line(file1);
	printf("File1: %s", str);
	free(str);
	str = get_next_line(file2);
	printf("File2: %s", str);
	free(str);
	close(file1);
	close(file2);
}
