/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:13:53 by mjander           #+#    #+#             */
/*   Updated: 2019/07/04 13:40:04 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char *line;
	int fd;

	fd = open("test.txt", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
		printf("%s,\n", line);
	free(line);
	close(fd);
	return (0);
}
