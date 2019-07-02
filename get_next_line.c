/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:52:13 by mjander           #+#    #+#             */
/*   Updated: 2019/07/02 10:48:47 by mjander          ###   ########.fr       */
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

char *ft_trim(char *src, char c)
{
	int i;
	
	i = 0;
	while (src[i] != c)
		i++;
	while (src[i])
		src[i++] = '\0';
	return (src);
}

int	ft_getline(const int fd, char **saved, char **buf)
{	
	int	ret;
	int end;
	char tmp[100000];

	end = 1;
	ft_bzero(tmp, 100000);
	while (!ft_strchr(tmp, '\n'))
	{
		ret = read(fd, *buf, BUFF_SIZE);
		if (ft_strchr(*buf, '\n'))
		{
			buf = ft_trim(*buf, '\n');
			tmp = ft_strcat(tmp, buf);
			return (end);
		}
		if (ret != BUFF_SIZE)
			end = 0;
		tmp = ft_strcat(tmp, buf);
	}

	*saved = ft_strcat(*saved, tmp);
	return (end);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*curr;
	char buf[BUFF_SIZE + 1];
	char newline[100000];
	char *ptr;			
	int				end;
	
	ft_bzero(buf,BUFF_SIZE + 1);
	ft_bzero(newline, 100000);
	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	curr = getfile(&file, fd);
	end = ft_getline(fd, &newline, &buf);
	*line = newline;
	ptr = curr->content;
	curr->content = ft_strjoin(curr->content, newline);
	free(ptr);
	return (end);
}

int main()
{
	char *line;
	int fd;

	fd = open("test.txt", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	free(line);
	close(fd);
	return (0);
}
