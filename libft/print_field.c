/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:38:38 by dmelessa          #+#    #+#             */
/*   Updated: 2019/04/12 23:38:38 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

out_func	g_out_funcs[] =
{
	NULL,
	out_l_horizontal_right,
	out_j_vertical_down,
	out_t_left,
	out_z_vertical,
	out_t_up,
	out_s_horizontal,
	out_i_vertical,
	out_l_vertical_down,
	out_s_vertical,
	out_t_right,
	out_j_horizontal_left,
	out_l_vertical_up,
	out_z_horizontal,
	out_j_vertical_up,
	out_quad,
	out_j_horizontal_right,
	out_t_down,
	out_l_horizontal_left,
	out_i_horizontal
};

void	print_figures(char **field, t_tetro *tetro_array, int size)
{
	t_tetro *buft = tetro_array;
	char	symb;

	symb = 'A';
	while (tetro_array->tetro_id != end)
	{
		if (tetro_array->tetro_id == start)
			tetro_array++;
		g_out_funcs[tetro_array->tetro_id](field, tetro_array->pos, symb, size);
		tetro_array++;
		symb++;
	}
	while(size-- > 0)
	{
		ft_putendl(*field);
		free(*field);
        field++;
	}
	free(buft);
	free(field);
}

int		print_field(int field_size, t_tetro **tetro_array)
{
	char	**field;
	int		buf;

	if (!(field = (char **)malloc(sizeof(char *) * (field_size))))
		return (0);
	buf = -1;
	while (++buf < field_size)
	{
		if (!(*(field + buf) = (char *)malloc(sizeof(char) * (field_size + 1))))
		{
			while (!buf)
			{
				buf--;
				free ((*(field + buf)));
			}
			free(field);
			return (0);
		}
		ft_bzero(*(field + buf), field_size + 1);
        ft_memset((void *)*(field + buf), (char)zero, field_size);
	}
	while ((*tetro_array)->tetro_id != start)
		(*tetro_array)--;
	print_figures(field, *tetro_array, field_size);
	return (1);
}
