/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:00:24 by gquence           #+#    #+#             */
/*   Updated: 2019/02/17 16:58:31 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*s_buf1;

	s_buf1 = s1;
	while (*s_buf1)
		s_buf1++;
	while (*s2)
	{
		*s_buf1++ = *s2++;
	}
	*s_buf1 = 0;
	return (s1);
}
