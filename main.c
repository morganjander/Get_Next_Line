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

void	ft_marks(char *s)
{
	int i = 0;
	int g = 0;
	int p = 0;
	int S = 0;
	int l = 0;
	int c = 0;
	while(s[i])
	{
		if (s[i] == 'g')
			g++;
		else if (s[i] == 'p')
			p++;
		else if (s[i] == 's')
			S++;
		else if (s[i] == 'l')
			l++;
		else if (s[i] == 'c')
			c++;
		i++;
	}

	printf("Grammar: %d\nPunctuation: %d\nSpelling: %d\nLanguage: %d\nClarity: %d\n", g, p, S, l, c);
}
int	main(void)
{
	char *line;
	int fd;

	fd = open("test.txt", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	ft_marks(line);
	free(line);
	close(fd);
	return (0);
}
