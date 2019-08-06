/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:37:50 by mjander           #+#    #+#             */
/*   Updated: 2019/06/19 14:44:46 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*freshstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	freshstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!freshstr)
		return (NULL);
	while (s1[i])
	{
		freshstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		freshstr[i] = s2[j];
		i++;
		j++;
	}
	freshstr[i] = '\0';
	return (freshstr);
}
