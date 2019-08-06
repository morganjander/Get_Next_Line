/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:44:51 by mjander           #+#    #+#             */
/*   Updated: 2019/06/20 08:48:45 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
/*
**void    freefunct(void *d, size_t s)
**{
**    free(d);
**    (void)s;
**}
**
**int        main(void)
**{
**    t_list    *begin;
**    size_t    v;
**
**    v = 1;
**    begin = ft_lstnew(&v, sizeof(void *));
**    begin->next = ft_lstnew(&v, sizeof(void *));
**    begin->next->next = ft_lstnew(&v, sizeof(void *));
**    ft_lstdelone(&begin->next->next, freefunct);
**    if (begin->next->next != NULL)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    ft_lstdelone(&begin->next, freefunct);
**    if (begin->next != NULL)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    ft_lstdelone(&begin, freefunct);
**    if (begin != NULL)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    write(1, "Success\n", 9);
**    return (1);
**}
*/
