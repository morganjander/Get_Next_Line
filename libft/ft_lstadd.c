/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:45:24 by mjander           #+#    #+#             */
/*   Updated: 2019/06/20 08:53:11 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
/*
**int        main(void)
**{
**    t_list    *begin;
**    t_list    *add;
**    t_list    *tmp;
**    size_t    v;
**
**    v = 1;
**    begin = ft_lstnew(&v, sizeof(size_t));
**    tmp = begin;
**    add = ft_lstnew(&v, sizeof(size_t));
**    ft_lstadd(&begin, add);
**    if (begin != add)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    if (begin->next != tmp)
**    {
**        write(1, "Didn't work\n", 16);
**        return (0);
**    }
**    free(begin->next);
**    free(begin);
**    write(1, "Success\n", 9);
**    return (0);
**}
*/
