/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduct_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <dmelessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:42:04 by gquence           #+#    #+#             */
/*   Updated: 2019/04/15 14:27:59 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**счётчик символов в строке (для проверки верности символов)
*/

static int		ft_strcountchr(const char *str, int c)
{
	int		result;

	if (!str)
		return (-1);
	result = 0;
	while (*str)
	{
		if (*str == c)
			result++;
		str++;
	}
	return (result);
}

static int		count_skip_rows(const char *str)
{
	int					count;

	count = 0;
	while (*str && *str == ZERO)
	{
		count++;
		str++;
	}
	return (count / 4);
}

static int		count_skip_columns(const char *str)
{
	int					count;
	int					i;
	int					multiplier;

	count = 0;
	i = 0;
	multiplier = 4;
	while (*(str + (i * multiplier + count)))
	{
		if (*(str + (i * multiplier + count)) == ONE)
			break ;
		i++;
		if (i == 4)
		{
			i = 0;
			count++;
		}
		if (count == 4)
			return (-1);
	}
	return (count);
}

int				get_tetro_id(const char *str)
{
	int					number;
	int					len;
	int					skipped;

	if (!str || !*str)
		return ((int)error);
	number = 0;
	len = ft_strlen(str);
	if (len != 16 || ft_strcountchr(str, (int)ONE) +
	ft_strcountchr(str, (int)ZERO) != len)
		return ((int)error);
	skipped = count_skip_columns(str) + count_skip_rows(str) * 4;
	str += skipped;
	while (*str)
	{
		number <<= 1;
		if (*str == ONE)
			number += 1;
		str++;
	}
	number <<= skipped;
	return (find_tetro_id(number, 1, 20));
}
