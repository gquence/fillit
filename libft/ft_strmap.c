/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:59:54 by gquence           #+#    #+#             */
/*   Updated: 2019/02/14 20:12:46 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buf;
	char	*b;

	if (!s || !(buf = (char *)malloc(sizeof(*buf) *
			(ft_strlen(s) + 1))))
		return (NULL);
	b = buf;
	if (!f || !s)
		return (NULL);
	while (*s)
	{
		*buf = f(*s);
		buf++;
		s++;
	}
	*buf = 0;
	return (b);
}
