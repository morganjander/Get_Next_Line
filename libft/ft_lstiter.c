/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:45:42 by mjander           #+#    #+#             */
/*   Updated: 2019/06/20 08:55:44 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		(*f)(lst);
		lst = lst->next;
	}
}
/*
**void    iterfunct(t_list *v)
**{
**    *(size_t*)v->content = *(size_t*)v->content + 1;
**}
**
**int        main(void)
**{
**    t_list    *begin;
**    size_t    i;
**    size_t    j;
**
**    i = 1;
**    j = 2;
**    begin = ft_lstnew(&i, sizeof(size_t));
**    begin->next = ft_lstnew(&j, sizeof(size_t));
**    ft_lstiter(begin, iterfunct);
**    if (*(size_t*)begin->content != 2)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    if (*(size_t*)begin->next->content != 3)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    free(begin->next);
**    free(begin);
**    write(1, "Success\n", 9);
**    return (1);
**}
*/
