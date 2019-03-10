/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:41:11 by gquence           #+#    #+#             */
/*   Updated: 2019/02/05 17:00:38 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest < src)
		return (ft_memcpy(dest, src, len));
	if (dest > src)
		while (len--)
			*((char *)dest + len) = *((char *)src + len);
	return (dest);
}
