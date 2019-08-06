/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:35:52 by mjander           #+#    #+#             */
/*   Updated: 2019/06/14 13:11:59 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*freshstr;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	freshstr = ft_strnew(ft_strlen(s));
	if (!freshstr)
		return (NULL);
	while (s[i] != '\0')
	{
		freshstr[i] = (*f)(s[i]);
		i++;
	}
	return (freshstr);
}
