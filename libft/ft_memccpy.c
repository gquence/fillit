/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:36:25 by gquence           #+#    #+#             */
/*   Updated: 2019/01/29 16:51:39 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest, void const *restrict src,\
		int c, size_t n)
{
	while (n--)
	{
		if ((*(char *)dest++ = *(char const *)src++) == (char)c)
			return (dest);
	}
	return (NULL);
}
