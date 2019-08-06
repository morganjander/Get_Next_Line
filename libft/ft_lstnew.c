/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:44:04 by mjander           #+#    #+#             */
/*   Updated: 2019/06/20 08:42:19 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
/*
**int		main(void)
**{
**	t_list	*begin;
**	size_t	i;
**
**	i = 1;
**	begin = ft_lstnew(NULL, 36);
**	if (begin != 0 && (begin->content_size != 0 || begin->content != NULL))
**	{
**		write(1, "Didn't work\n", 16);
**		return (0);
**	}
**	free(begin);
**	begin = ft_lstnew(&i, sizeof(size_t));
**	if (begin != NULL)
**	{
**		if (&i == begin->content)
**		{
**		write(1, "Didn't work\n", 16);
**		return (0);
**		}
**		if (*(size_t*)begin->content != 1)
**		{
**		write(1, "Didn't work\n", 16);
**		return (0);
**		}
**		if (begin->content_size != sizeof(size_t))
**		{
**		write(1, "Didn't work\n", 16);
**		return (0);
**		}
**		if (begin->next != 0)
**		{
**		write(1, "Didn't work\n", 16);
**		return (0);
**		}
**	}
**	free(begin);
**	write(1, "Success\n", 9);
**	return (0);
**}
*/
