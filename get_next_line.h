/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjander <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:54:04 by mjander           #+#    #+#             */
/*   Updated: 2019/06/20 11:03:01 by mjander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define	GET_NEXT_LINE_H

#include "libft.h"

int		get_next_line(const int fd, char **line);

#define BUFF_SIZE 32

#endif
