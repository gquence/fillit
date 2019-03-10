/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:12:25 by gquence           #+#    #+#             */
/*   Updated: 2019/02/05 17:43:03 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t len;

	len = ft_strlen(s);
	if (c == '\0')
		return (((char *)s + len));
	i = 0;
	while (i < len)
		if (*(s + i) == c)
			return ((char *)s + i);
		else
			i++;
	return (NULL);
}
