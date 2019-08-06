/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:38:18 by mjander           #+#    #+#             */
/*   Updated: 2019/06/19 15:11:49 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const *new;

	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	new = s + ft_strlen(s) - 1;
	while (ft_iswhitespace(*new))
		new--;
	return (ft_strsub(s, 0, new - s + 1));
}
