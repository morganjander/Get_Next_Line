/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:22:29 by mjander           #+#    #+#             */
/*   Updated: 2019/06/19 15:08:30 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Always call memmove with len multiplied by the size of
** `each element eg memmove(dst, src, len * sizeof(elem_type)
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	unsigned char const	*src1;

	if (dst == src)
		return (dst);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned const char *)src;
	if (src <= dst)
	{
		dst1 = dst1 + (len - 1);
		src1 = src1 + (len - 1);
		while (len--)
			*dst1-- = *src1--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
