/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <gquence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:49:44 by dmelessa          #+#    #+#             */
/*   Updated: 2019/04/09 13:02:15 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//в массиве хранятся функции размещения на поле для каждого тетармино
place_func	g_place_funcs[] =
{	
	NULL,
	place_l_horizontal_right,
	place_j_vertical_down,
	place_t_left,
	place_z_vertical,
	place_t_up,
	place_s_horizontal,
	place_i_vertical,
	place_l_vertical_down,
	place_s_vertical,
	place_t_right,
	place_j_horizontal_left,
	place_l_vertical_up,
	place_z_horizontal,
	place_j_vertical_up,
	place_quad,
	place_j_horizontal_right,
	place_t_down,
	place_l_horizontal_left,
	place_i_horizontal,
};

del_func	g_del_funcs[] =
{
	NULL,
	del_l_horizontal_right,
	del_j_vertical_down,
	del_t_left,
	del_z_vertical,
	del_t_up,
	del_s_horizontal,
	del_i_vertical,
	del_l_vertical_down,
	del_s_vertical,
	del_t_right,
	del_j_horizontal_left,
	del_l_vertical_up,
	del_z_horizontal,
	del_j_vertical_up,
	del_quad,
	del_j_horizontal_right,
	del_t_down,
	del_l_horizontal_left,
	del_i_horizontal
};

/*
** Принимает ссылку указателя на поле field размера size и указатель на терамино,
** которое надо поставить на позицию pos
** pos имзеняется внутри функции
** возвращет целочисленное значени
** 0 - значить не удалось поставить
** 1 - поставили тетрамино на позицию pos 
** -1 - больше некуда ставить
** если tetro_id == start возвращает 1
*/
int 		place_figure(long *field, int size, int *pos, t_tetro *tetro_ref)
{
	int			status;

	if (tetro_ref->tetro_id == start)
		return (1);
	status = (*(g_place_funcs + tetro_ref->tetro_id))(field, size, *pos);// получаем отдельную
	// функцию размещения для тетрамино в зависимости от tetra_id
	if (status == 1)
	{
		tetro_ref->pos = *pos;
		*pos = 0;
		return (1);
	}
	else if (status == 0)
		return (0);
	return (-1);
}

/*
** удаляет тетрамино tetro_array с поля field размером field_size на позиции pos,
** pos устанавливается на единицу большим, чем текущее положение тетрамино
*/
int del_figure(long *field, int size, t_tetro *ptetro, int *pos)
{
	if (ptetro->tetro_id == start)
	{
		*pos = 0;
		return (1);
	}
	*pos = ptetro->pos + 1;
	(*(g_del_funcs + ptetro->tetro_id))(field, size, ptetro->pos);
	ptetro->pos = -1;
	return (0);
}

void 		find_solution(int fd)
{
	t_tetro	*tetro_array;
	long 	field[16];
	int 	status;
	int 	field_size;
	int 	pos;//pos -- позиция поля, на которую ставим тетрамино

	field_size = (0.99 + ft_sqrt(4 * get_tetros(&tetro_array, fd))); // минимально требуемый размер для поля
	ft_bzero(field, sizeof(long) * field_size);
	pos = 0;
	while ((tetro_array)->tetro_id != end) // цикл где происходят размещения
	{
		status = place_figure((long *)field, field_size, &pos, tetro_array);
		if (status == 0) // не удалось поставить
			pos++;
		else if (status == 1) // поставили
			tetro_array++;	//pos = 0
		else if (status == -1) // больше некуда ставить
		{
			tetro_array--;		
			if (del_figure((long *)field, field_size, tetro_array, &pos) == 1)
				ft_bzero(field, sizeof(long) * ++field_size);
		}	
	}
	print_field(field_size, &tetro_array);
	free(tetro_array);
}

int			main(int argc, char **argv)
{
	int 	fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
	{
		ft_putendl("error");
		return (-1);
	}
	find_solution(fd);
	return (0);
}
