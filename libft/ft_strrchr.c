/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:13:01 by gquence           #+#    #+#             */
/*   Updated: 2019/01/29 18:13:06 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *s1;

	s1 = (char *)s;
	while (*s)
		s++;
	if (c == 0)
		return ((char *)s);
	while (s >= s1)
		if (*s-- == c)
			return ((char *)++s);
	return (NULL);
}
