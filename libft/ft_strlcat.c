/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:11:05 by gquence           #+#    #+#             */
/*   Updated: 2019/01/29 17:12:04 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (n < s1_len)
		return (n + s2_len);
	i = 0;
	while (s2[i] != 0 && (s1_len + i + 1) < n)
	{
		s1[s1_len + i] = s2[i];
		++i;
	}
	s1[s1_len + i] = 0;
	return (s1_len + s2_len);
}
