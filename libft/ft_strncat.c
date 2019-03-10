/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:10:29 by gquence           #+#    #+#             */
/*   Updated: 2019/01/29 17:43:06 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*s_buf1;

	s_buf1 = s1;
	while (*s_buf1)
		s_buf1++;
	while (*s2 && n--)
	{
		*s_buf1++ = *s2++;
	}
	*s_buf1 = 0;
	return (s1);
}
