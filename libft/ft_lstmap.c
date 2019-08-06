/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:46:05 by mjander           #+#    #+#             */
/*   Updated: 2019/06/20 08:59:09 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;

	if (!lst)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
/*
**t_list        *iterfunct(t_list *elem)
**{
**    t_list    *new;
**    char    *content;
**    size_t    i;
**
**    content = ft_strdup((char *)(elem->content));
**    i = 0;
**    while (i < ft_strlen(content))
**    {
**        content[i] += 1;
**        ++i;
**    }
**    new = ft_lstnew((void const *) content, 5);
**    free(content);
**    return (new);
**}
**
**int            main(void)
**{
**    t_list            *lst_initial;
**    t_list            *lst;
**    char            *content;
**    t_list            *(*f)(t_list *);
**
**    content = "toto";
**    lst_initial = ft_lstnew((void const *) content, 5);
**    content = "tata";
**    lst_initial->next = ft_lstnew((void const *) content, 5);
**    content = "tutu";
**    lst_initial->next->next = ft_lstnew((void const *) content, 5);
**    f = &iterfunct;
**    lst = ft_lstmap(lst_initial, f);
**    if (!strcmp((const char *) lst->content, (const char *) lst_in
**itial->content) || strcmp((const char *) lst->content, "upup"))
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    if (!strcmp((const char *) lst->next->content, (const ch
**ar *) lst_initial->next->content) || strcmp((const char *
**) lst->next->content, "ubub"))
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    if (!strcmp((const char *) lst->next->next->content, (con
**st char *) lst_initial->next->next->content) || strcmp((con
**st char *) lst->next->next->content, "uvuv"))
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    write(1, "Success\n", 9);
**    return (0);
**}
*/
