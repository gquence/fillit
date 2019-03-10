/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:17:30 by gquence           #+#    #+#             */
/*   Updated: 2019/02/17 17:06:28 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		sign;
	char	*p;
	int		size;
	int		tmp;

	size = 1;
	sign = n < 0 ? 1 : 0;
	tmp = n;
	while (tmp /= 10)
		size++;
	if (!(p = (char *)malloc(size + sign + 1)))
		return (NULL);
	*(p + sign + size) = '\0';
	if (sign)
		*p++ = '-';
	while (size--)
	{
		*(p + size) = (((n % 10) < 0) ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (p - sign);
}
