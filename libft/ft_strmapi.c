/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:59:54 by gquence           #+#    #+#             */
/*   Updated: 2019/02/14 20:13:16 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	char	*b;

	if (!s || !(buf = (char *)malloc(sizeof(*buf)
			* (ft_strlen((char *)s) + 1))))
		return (NULL);
	b = buf;
	if (!f)
		return (NULL);
	while (*s)
	{
		*buf = f(buf - b, *s);
		buf++;
		s++;
	}
	*buf = 0;
	return (b);
}
