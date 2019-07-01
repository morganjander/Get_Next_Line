/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:52:13 by mjander           #+#    #+#             */
/*   Updated: 2019/06/29 14:49:58 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

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

int				get_next_line(const int fd, char **line)
{
	char			*buf(BUFF_SIZE + 1);
	static t_list	*file;
	t_list			*curr;
	int				i;
	int				ret;

	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	curr = getfile(&file, fd);
	while (ret = read(fd, buf, BUFF_SIZE))
	{
		buf[ret] = '\0';
		curr->content = ft_strjoin(curr->content, buf);
		if (ft_strchr(buf, '\n'))
			 ;
	}
	if (ret < BUFF_SIZE && ret != ft_strlen(curr->content))
		return (0);


	return (0);
}
