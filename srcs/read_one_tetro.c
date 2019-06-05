/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_one_tetro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <dmelessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:48:40 by gquence           #+#    #+#             */
/*   Updated: 2019/04/15 14:26:38 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short int	g_tetra_value[20] =
{
	0,
	11776,
	17600,
	19520,
	19584,
	19968,
	27648,
	34952,
	35008,
	35904,
	35968,
	36352,
	50240,
	50688,
	51328,
	52224,
	57856,
	58368,
	59392,
	61440
};

int				find_tetro_id(const unsigned short int number,
							size_t b_border, size_t h_border)
{
	size_t	prev_bb;
	size_t	prev_hb;
	int		pos;

	prev_bb = 100;
	prev_hb = 100;
	while (prev_bb != b_border || prev_hb != h_border)
	{
		pos = (int)((h_border - b_border) / 2) + b_border;
		if (g_tetra_value[pos] == number)
			return (pos);
		if (g_tetra_value[pos] < number)
		{
			prev_bb = b_border;
			prev_hb = h_border;
			b_border = pos;
		}
		if (g_tetra_value[pos] > number)
		{
			prev_bb = b_border;
			prev_hb = h_border;
			h_border = pos;
		}
	}
	return ((int)error);
}

int				convert_to_tetro(const char *line, char *ptetro)
{
	int		i;
	char	*tetro;

	i = 0;
	tetro = ptetro;
	while (i != 4)
	{
		if (line[i] != (char)ZERO && line[i] != (char)ONE)
			return (0);
		tetro[i] = line[i];
		i++;
	}
	if (line[i] != '\n')
		return (0);
	return (1);
}

static int		check_ret(const int ret, int *n_koef, char *line)
{
	if (!ret && !(*n_koef))
		return ((int)end);
	if (ret != 21 && ret != 20)
		return ((int)error);
	if (ret == 21)
	{
		if (line[20] != '\n')
			return ((int)error);
		*n_koef = 1;
	}
	else
		*n_koef = 0;
	return ((int)start);
}

int				read_one_tetro(const int fd)
{
	char				line[22];
	char				tetro_line[17];
	int					line_count;
	int					ret;
	static int			n_koef;

	ft_memset((void *)line, 0, 22);
	ft_memset((void *)tetro_line, 0, 17);
	ret = read(fd, &line, 21);
	if ((line_count = check_ret(ret, &n_koef, line)) == (int)end)
		return ((int)end);
	if (line_count == (int)error)
		return ((int)error);
	line_count = 0;
	while (line_count != 4)
	{
		if (!convert_to_tetro((line + (line_count * 5)),
				(tetro_line + (line_count * 4))))
			return ((int)error);
		line_count++;
	}
	return (get_tetro_id(tetro_line));
}

/*
** передаем адресс указателя, который должен указывать на массив тетрамино
** возвращает количество тетрамино
*/

int				get_tetros(t_tetro **tetro_array, int fd)
{
	int	pos;

	pos = 0;
	*tetro_array = (t_tetro *)malloc(sizeof(t_tetro) * 28);
	(*tetro_array)->tetro_id = start;
	(*tetro_array)->pos = -1;
	while ((((*tetro_array) + ++pos)->tetro_id =
			(t_tetro_id)read_one_tetro(fd)) != end
			|| ((*tetro_array) + 1)->tetro_id == end)
	{
		((*tetro_array) + pos)->pos = -1;
		if (((*tetro_array) + pos)->tetro_id == error || pos > 26)
		{
			free(*tetro_array);
			ft_putstr("error\n");
			exit(0);
		}
	}
	return (pos - 1);
}
