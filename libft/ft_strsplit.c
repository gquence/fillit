/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:06:16 by gquence           #+#    #+#             */
/*   Updated: 2019/02/17 19:19:10 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_ch(char const *s, char c)
{
	int		res;

	res = 0;
	while (*s != c && *s++)
		res++;
	return (res);
}

static char		**ft_free_strs(char ***pstrs)
{
	char	**strs;

	if (!pstrs || !*pstrs || !**pstrs)
		return (NULL);
	strs = *pstrs;
	while (*strs)
	{
		free(*strs);
		strs++;
	}
	free(*pstrs);
	return (NULL);
}

static int		ft_split_count(char const *s, char c)
{
	int		i;

	i = 1;
	while (*s)
	{
		if (!ft_strlen_ch(s, c))
		{
			s++;
			continue;
		}
		else if (ft_strlen_ch(s, c) == ft_strlen(s))
		{
			i++;
			return (i);
		}
		else
		{
			i++;
			while (ft_strlen_ch(s, c))
				s++;
		}
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**strs;
	char	**buf;
	char	*s_buf;

	if (!s || !(strs = (char **)malloc(sizeof(*strs) * ft_split_count(s, c))))
		return (NULL);
	buf = strs;
	while (*s)
	{
		if (!ft_strlen_ch(s, c))
		{
			s++;
			continue ;
		}
		if (!(*strs = (char *)malloc(sizeof(**strs) *
				(ft_strlen_ch(s, c) + 1))))
			return (ft_free_strs(&buf));
		s_buf = *strs;
		while (ft_strlen_ch(s, c))
			*s_buf++ = *s++;
		*s_buf = 0;
		strs++;
	}
	*strs = NULL;
	return (buf);
}
