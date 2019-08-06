/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:36:10 by mjander           #+#    #+#             */
/*   Updated: 2019/06/14 12:36:19 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*freshstr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	freshstr = ft_strnew(ft_strlen(s));
	if (!freshstr)
		return (NULL);
	while (*(s + i))
	{
		freshstr[i] = (*f)(i, s[i]);
		i++;
	}
	return (freshstr);
}
