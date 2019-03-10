/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:12:34 by gquence           #+#    #+#             */
/*   Updated: 2019/02/14 19:30:29 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*sbuf;

	if (!s || (int)len < 0 || (int)start < 0)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	sbuf = str;
	while (*(s + start) && len--)
	{
		*str++ = *(char*)(s + start);
		start++;
	}
	*str = 0;
	return (sbuf);
}
