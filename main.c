/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:22:46 by dmelessa          #+#    #+#             */
/*   Updated: 2019/03/17 17:43:52 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/includes/libft.h"
#define ABS(x) (((x) < 0) ? (-(x)) : (x))
//#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void 		print_field(long *in_field, int field_size)
{
	for (int i = 0; i < field_size; i++)
	{
		for (int j = 0; j < field_size; j++)
		{
			printf("%d ", (in_field[i]>>j) & 1);
		}
		printf("\n");
	}
}

/*
** Установка квадрата на поле field, размера field_size на клетку pos
** возвращаемые значения:
** 0 - не удалось поставить
** 1 - поставили
** -1 - больше некуда ставить
*/
int			place_quad(long **field, int field_size, int pos)
{
	int 	column;
	int 	row;
	long 	*pfield;

	if (pos % field_size == field_size - 1)
		return (0);
	if (pos >= (field_size * (field_size - 1)))
		return (-1);
	pfield = *field;
	column = pos / field_size;
	row = pos % field_size;	
	if (((*(pfield +column) >> row) & 1) == 0 
		&& ((*(pfield +column) >> (row + 1)) & 1) == 0
		&& ((*(pfield + column + 1) >> row) & 1) == 0 
		&& ((*(pfield + column + 1) >> (row + 1)) & 1) == 0)
	{
		*(pfield + column) |= 1<<row;
		*(pfield + column) |= 1<<(row + 1);
		*(pfield + column + 1) |= 1<<row;
		*(pfield + column + 1) |= 1<<(row + 1);
		return (1);
	}
	return (0);
}

int			place_error(long **field, int field_size, int pos)
{
	return (1);
}

//в массиве хрнятся функции размещения на поле для каждого тетармино
place_func	g_place_funcs[] =
{	
			place_error,
			place_quad
			/*place_i_vertical,
			place_i_horizontal,
			place_z_vertical,
			place_z_horizontal,
			place_s_vertical,
			place_s_horizontal,
			place_l_vertical_up,
			place_l_vertical_down,
			place_l_horizontal_right,
			place_l_horizontal_left,
			place_j_vertical_up,
			place_j_vertical_down,
			place_j_horizontal_right,
			place_j_horizontal_left,
			place_t_up,
			place_t_right,
			place_t_down,
			place_t_left*/
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
int 		place_figure(long **field, int size, int *pos, t_tetro *tetro_ref)
{
	int			status;

	if (tetro_ref->tetro_id == start)
		return (1);
	status = g_place_funcs[tetro_ref->tetro_id](field, size, *pos);// получаем отдельную
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


void		arr_t_tetro_copy(t_tetro **arr_dest, const t_tetro *arr_src, size_t tetro_count)
{
	int				pos;
	t_tetro			*result_arr;

	if (!arr_dest || !*arr_dest)
		return ;
	if (!(*arr_dest = (t_tetro *)malloc(sizeof(t_tetro) * (tetro_count + 2))))
		return ;
	pos = 0;
	result_arr = *arr_dest;
	while (pos <= tetro_count)
	{
		result_arr[pos].pos = arr_src[pos].pos;
		result_arr[pos].tetro_id = arr_src[pos].tetro_id;
		pos++;
	}
	result_arr[pos].tetro_id = end;
	return ;
}
// передаем адрес указателя, который должен указывать на массив тетрамино
// возвращает количество тетрамино
int 		get_tetros(t_tetro **tetro_array, int fd)
{
	t_tetro			*ptetro_array;
	unsigned int	pos;

	pos = 1;
	ptetro_array = (t_tetro *)malloc (sizeof(t_tetro) * 28);
	ptetro_array->tetro_id = start;
	ptetro_array->pos = -1;
	while ((ptetro_array[pos].tetro_id = (t_tetro_id)read_one_tetro(fd)) != end)
	{
		ptetro_array[pos].pos = -1;
		if (ptetro_array[pos].tetro_id == error || pos > 26)
		{
			free(ptetro_array);
			ft_putstr("error\n");
			exit(0);
		}
		pos++;
	}
	arr_t_tetro_copy(tetro_array, ptetro_array, pos - 1);
	free(ptetro_array);
	return (pos - 1);
}

float 		ft_sqrt(int a)
{
    float y;

	y = a / 2;
    while (ABS(y * y - a) > 0.0001)
        y = (a / y + y) / 2;
	return (y);
}

long		*generate_field(int field_size)
{
	long	*field;
	int		i;

	if (!(field = malloc(sizeof(long) * field_size)))
		return (NULL);
	i = -1;
	while (++i < field_size)
	{
		*(field + i) = 0;
	}	
	return (field);
}

/*
** вызывается в случае если
** все варианты на поле размером field_size проверены 
*/ 	
void		generate_new_field(long **field, int field_size)
{
	int i;

	free(*field);
	*field = malloc(sizeof(long) * field_size);
	i = -1;
	while (++i < field_size)
	{
		**field = 0;
	}
}

int 		delete_figure(long **field, int field_size, t_tetro **tetro_array, int *pos)
{
	int 	column;
	int 	row;
	long 	*pfield;

	if ((*tetro_array)->tetro_id == start)
	{
		*pos = 0;
		return (0);
	}
	pfield = *field;
	column = *pos / field_size;
	row = *pos % field_size;	
	*(pfield + column) &= ~(1 << row);
	*(pfield + column) &= ~(1<<(row + 1));
	*(pfield + column + 1) &= ~(1<<row);
	*(pfield + column + 1) &= ~(1<<(row + 1));
	*pos = (*tetro_array)->pos + 1;
	(*tetro_array)->pos = -1;
	return (1);
}

void 		find_solution(int fd)
{
	t_tetro	*tetro_array;
	long 	*field;
	int 	status;
	int 	field_size;
	int 	pos; //pos -- позиция поля, на которую ставим тетрамино

	field_size = (0.99 + ft_sqrt(4 * get_tetros(&tetro_array, fd))); // минимально требуемый
	// размер для поля
	field = generate_field(field_size);
	pos = 0;
	while ((tetro_array)->tetro_id != end) // цикл где происходят размещения
	{
		status = place_figure(&field, field_size, &pos, tetro_array);
		if (status == 0) // не удалось поставить
			pos++;
		else if (status == 1) // поставили
			tetro_array++;	//pos = 0
		else if (status == -1) // больше некуда ставить
		{
			tetro_array--;		
			if (delete_figure(&field, field_size, &tetro_array, &pos) == 0)//если tetro_id == start
				generate_new_field(&field, (++field_size));
		}
	}
	print_field(field, field_size);
}

int			main(int argc, char **argv)
{
	int 	fd;
	int		pos;
	if (argc == 1)
		return (1);
	if (argc > 2)
		return (-1);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
	t_tetro *result;
	pos = 0;
	get_tetros(&result, fd);
	while (result[pos].tetro_id != end)
	{
		printf("%d\t", result[pos].tetro_id);
		pos++;
	}
	free(result);
	//find_solution(fd);
	return (0);
}
