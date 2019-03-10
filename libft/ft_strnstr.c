/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:43:47 by gquence           #+#    #+#             */
/*   Updated: 2019/02/17 12:58:40 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *pneedle = needle;

	if (!*needle)
		return ((char *)haystack);
	while (len-- && *haystack && *needle)
		if (*haystack++ == *needle)
			needle++;
		else
		{
			haystack -= needle - pneedle;
			len += needle - pneedle;
			needle = pneedle;
		}
	return (*needle ? NULL : (char *)(haystack - (needle - pneedle)));
}
