/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:37:21 by mjander           #+#    #+#             */
/*   Updated: 2019/06/14 13:22:16 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *freshstr;

	freshstr = ft_strnew(len);
	if (!freshstr || !s || !*(s + start))
		return (0);
	freshstr = (char *)ft_memmove(freshstr, (s + start), len);
	return (freshstr);
}
