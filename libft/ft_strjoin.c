/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:15:28 by gquence           #+#    #+#             */
/*   Updated: 2019/02/14 19:27:51 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *buf;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1)
			+ ft_strlen(s2) + 1))))
		return (NULL);
	buf = str;
	while (*s1)
		*str++ = (char)*s1++;
	while (*s2)
		*str++ = (char)*s2++;
	*str = 0;
	return (buf);
}
