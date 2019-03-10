/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:09:45 by gquence           #+#    #+#             */
/*   Updated: 2019/02/14 20:02:21 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_strlen_wout(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	while (*str)
	{
		i++;
		str++;
	}
	while ((*(str - 1) == ' ' || *(str - 1) == '\n' || *(str - 1) == '\t') && i)
	{
		i--;
		str--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	char	*buf;
	int		str_len;
	int		count;

	count = 0;
	if (!s)
		return (NULL);
	while ((*s == '\n' || *s == '\t' || *s == ' ') && *s)
		s++;
	str_len = ft_strlen_wout(s);
	if (!(str = (char *)malloc(sizeof(*str) * (str_len + 1))))
		return (NULL);
	buf = str;
	while (*s && count < str_len)
	{
		if (*s == '\n' || *s == '\t' || *s == ' ')
			if (!*(s + 1))
				break ;
		*str++ = (char)*s++;
		count++;
	}
	*str = 0;
	return (buf);
}
