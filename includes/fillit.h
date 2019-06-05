/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <dmelessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:49:59 by dmelessa          #+#    #+#             */
/*   Updated: 2019/04/15 14:25:44 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>

/*
** устанвливает i-ый бит в var равным 1
*/

# define SET_BIT(var, i) (var) |= 1<<(i);

/*
** устанвливает i-ый бит в var равным 0
*/

# define ZERO_BIT(var, i) (var) &= ~(1<<(i));

/*
** проверка является ли i-ый бит в var нулевым
*/

# define CHECK_BIT(var, i) (((var) >> (i)) & 1) == 0

typedef enum	e_tetro_id
{
	error = -1,
	start,
	l_horizontal_right,
	j_vertical_down,
	t_left,
	z_vertical,
	t_up,
	s_horizontal,
	i_vertical,
	l_vertical_down,
	s_vertical,
	t_right,
	j_horizontal_left,
	l_vertical_up,
	z_horizontal,
	j_vertical_up,
	quad,
	j_horizontal_right,
	t_down,
	l_horizontal_left,
	i_horizontal,
	end
}				t_tetro_id;

/*
** One tetro information
** pos -- postion top left piece
** if tetro not placed pos = -1
*/

typedef struct	s_tetro
{
	t_tetro_id	tetro_id;
	int			pos;
}				t_tetro;

/*
**prototypes of placing functions for each tetramino
*/

/*
** Установка квадрата на поле field, размера field_size на клетку pos
** возвращаемые значения:
** 0 - не удалось поставить
** 1 - поставили
** -1 - больше некуда ставить
*/

int				place_quad(long *field, int field_size, int pos);
int				place_i_vertical(long *field, int field_size, int pos);
int				place_i_horizontal(long *field, int field_size, int pos);
int				place_z_vertical(long *field, int field_size, int pos);
int				place_z_horizontal(long *field, int field_size, int pos);
int				place_s_vertical(long *field, int field_size, int pos);
int				place_s_horizontal(long *field, int field_size, int pos);
int				place_l_vertical_up(long *field, int field_size, int pos);
int				place_l_vertical_down(long *field, int field_size, int pos);
int				place_l_horizontal_right(long *field, int field_size, int pos);
int				place_l_horizontal_left(long *field, int field_size, int pos);
int				place_j_vertical_up(long *field, int field_size, int pos);
int				place_j_vertical_down(long *field, int field_size, int pos);
int				place_j_horizontal_right(long *field, int field_size, int pos);
int				place_j_horizontal_left(long *field, int field_size, int pos);
int				place_t_up(long *field, int field_size, int pos);
int				place_t_right(long *field, int field_size, int pos);
int				place_t_left(long *field, int field_size, int pos);
int				place_t_down(long *field, int field_size, int pos);

/*
** prototypes of deleting functions for each tetramino
*/

int				del_figure(long *field, int size, t_tetro *ptetro, int *pos);
void			del_error(long *field, int size, int pos);
void			del_quad(long *field, int size, int pos);
void			del_i_vertical(long *field, int size, int pos);
void			del_i_horizontal(long *field, int size, int pos);
void			del_z_vertical(long *field, int size, int pos);
void			del_z_horizontal(long *field, int size, int pos);
void			del_s_vertical(long *field, int size, int pos);
void			del_s_horizontal(long *field, int size, int pos);
void			del_l_vertical_up(long *field, int size, int pos);
void			del_l_vertical_down(long *field, int size, int pos);
void			del_l_horizontal_right(long *field, int size, int pos);
void			del_l_horizontal_left(long *field, int size, int pos);
void			del_j_vertical_up(long *field, int size, int pos);
void			del_j_vertical_down(long *field, int size, int pos);
void			del_j_horizontal_right(long *field, int size, int pos);
void			del_j_horizontal_left(long *field, int size, int pos);
void			del_t_up(long *field, int size, int pos);
void			del_t_right(long *field, int size, int pos);
void			del_t_left(long *field, int size, int pos);
void			del_t_down(long *field, int size, int pos);

int				print_field(int field_size, t_tetro **tetro_array);
void			print_figures(char **field, t_tetro *tetro_array, int size);

void			out_l_horizontal_right(char **field, int pos,
					char c, int field_size);
void			out_j_vertical_down(char **field, int pos,
					char c, int field_size);
void			out_t_left(char **field, int pos, char c, int field_size);
void			out_z_vertical(char **field, int pos, char c, int field_size);
void			out_t_up(char **field, int pos, char c, int field_size);
void			out_s_horizontal(char **field, int pos,
					char c, int field_size);
void			out_i_vertical(char **field, int pos, char c, int field_size);
void			out_l_vertical_down(char **field, int pos,
					char c, int field_size);
void			out_s_vertical(char **field, int pos, char c, int field_size);
void			out_t_right(char **field, int pos, char c, int field_size);
void			out_j_horizontal_left(char **field, int pos,
					char c, int field_size);
void			out_l_vertical_up(char **field, int pos,
					char c, int field_size);
void			out_z_horizontal(char **field, int pos, char c, int field_size);
void			out_j_vertical_up(char **field, int pos,
					char c, int field_size);
void			out_quad(char **field, int pos, char c, int field_size);
void			out_j_horizontal_right(char **field, int pos,
					char c, int field_size);
void			out_t_down(char **field, int pos, char c, int field_size);
void			out_l_horizontal_left(char **field, int pos,
					char c, int field_size);
void			out_i_horizontal(char **field, int pos, char c, int field_size);

typedef int		(*t_place_func)(long *field, int field_size, int pos);
typedef void	(*t_del_func)(long *field, int size, int pos);
typedef void	(*t_out_func)(char **field, int pos, char c, int size);

/*
**must be deleted before release (usage in file "get_tetro_id.c")
*/
# define ONE '#'
# define ZERO '.'

/*
**функции используемые для считывания
*/
int				get_tetros(t_tetro **tetro_array, int fd);
int				read_one_tetro(const int fd);
int				get_tetro_id(const char *str);
int				find_tetro_id(const unsigned short int number,
					size_t b_border, size_t h_border);

#endif
