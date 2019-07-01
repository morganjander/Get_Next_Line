/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:52:13 by mjander           #+#    #+#             */
/*   Updated: 2019/07/01 11:12:47 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

static t_list	*getfile(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("/0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

char *ft_copyuntil(char *src, char c)
{
	char *str;
	int i = 0;

	while (src[i] != c)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = src[i];
	}
	return (str);
}

int	ft_getline(const int fd, char **saved)
{
	char buf[BUFF_SIZE + 1];
	char *tmp;
	int	ret;
	int end;
	
	end = 0;
	while (!ft_strchr(*saved, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tmp = ft_strdup(*saved);
		free (*saved);
		*saved = ft_strjoin(tmp, buf);
		free(tmp);
		if (ret < BUFF_SIZE)
			end = 1; //reached the end of the file?
			break ;
	}
	tmp = ft_copyuntil(*saved, '\n');
	free(*saved);
	*saved = ft_strdup(tmp);
	free(tmp);
	return (end);
}

int				get_next_line(const int fd, char **line)
{
	char			*buf[BUFF_SIZE + 1];
	static t_list	*file;
	t_list			*curr;
	int				end;

	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	curr = getfile(&file, fd);
	end = ft_getline(fd, (char **)&curr->content);
	*line = ft_strdup((char *)&curr->content);
	return (end);
}

int main()
{
	char *line;
	int fd;

	fd = open("test.rtf", O_RDONLY);

	line = malloc(1);
	line[0] = 0;
	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
	}
	free(line);
	close(fd);
	return (0);
}
