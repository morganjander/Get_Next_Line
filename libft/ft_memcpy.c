/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:27:46 by mjander           #+#    #+#             */
/*   Updated: 2019/06/19 15:17:53 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst1;
	char const	*src1;

	i = -1;
	dst1 = (char *)dst;
	src1 = (char const *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (++i < n)
		dst1[i] = src1[i];
	return (dst);
}
