/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:14:43 by gquence           #+#    #+#             */
/*   Updated: 2019/02/17 13:03:32 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *sbuf2;
	char *sbuf1;

	sbuf2 = (char *)needle;
	if (!*haystack && !*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		sbuf1 = (char *)haystack;
		while (*(char *)haystack == *sbuf2 && *haystack && *sbuf2)
		{
			haystack++;
			sbuf2++;
		}
		if (*sbuf2 != 0)
		{
			sbuf2 = (char *)needle;
			haystack = (const char *)sbuf1;
		}
		else
			return ((char *)haystack - (sbuf2 - (char *)needle));
		haystack++;
	}
	return (NULL);
}
