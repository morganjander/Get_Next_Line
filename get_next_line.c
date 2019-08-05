/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:52:13 by mjander           #+#    #+#             */
/*   Updated: 2019/07/04 13:49:32 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft-Project/libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/*
** returns the correct node in the list of files,
** using content_size as an identifier. Creates a
** new node with an empty string if one with the
** correct fd does not exist
*/

static t_list	*getfile(t_list **files, int fd)
{
	t_list	*tmp;

	tmp = *files;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(files, tmp);
	tmp = *files;
	return (tmp);
}

/*
** reads from the fd into the buffer, then assigns
** the content of buffer into the saved string,
** until the saved string contains a newline
** character.
*/

void			read_until(int fd, char **saved)
{
	char	buf[BUFF_SIZE + 2];
	char	*tmp;
	int		ret;

	while (!(ft_strchr(*saved, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = (ret < BUFF_SIZE) ? 3 : 0;
		buf[ret + 1] = 0;
		tmp = ft_strdup(*saved);
		free(*saved);
		*saved = ft_strjoin(tmp, buf);
		free(tmp);
		if (!ret)
			return ;
	}
}

/*
** checks if the 1st char of the saved sting is the eof character
** (reached the end of the file, so returns 0)
** assigns a ptr to the newline char in the saved string,
** replaces it with null, copies the string up until null
** into the line, then frees string and copies whatever
** is after null (newline) back into the string.
*/

int				ft_getline(char **saved, char **line)
{
	char	*tmp;
	char	*ptr;
	char	*eof;

	if ((*saved)[0] == 3)
		return (0);
	if ((eof = ft_strchr(*saved, 3)))
		if (!(ft_strchr(*saved, '\n')))
			*eof = '\n';
	tmp = ft_strdup(*saved);
	ptr = ft_strchr(tmp, '\n');
	*ptr = 0;
	*line = ft_strdup(tmp);
	free(*saved);
	*saved = ft_strdup(ptr + 1);
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*curr;

	if (fd < 0 || !line || (read(fd, 0, 0) < 0))
		return (-1);
	curr = getfile(&files, fd);
	read_until(fd, (char **)&curr->content);
	return (ft_getline((char **)&curr->content, line));
}
