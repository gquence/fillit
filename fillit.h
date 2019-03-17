/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:20:45 by dmelessa          #+#    #+#             */
/*   Updated: 2019/03/17 17:43:46 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
//# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <time.h>

//prototypes of placing functions for each tetramino
int				place_error(long **field, int field_size, int pos);
int				place_quad(long **field, int field_size, int pos);
int				place_i_vertical(long **field, int field_size, int pos);
int				place_i_horizontal(long **field, int field_size, int pos);
int				place_z_vertical(long **field, int field_size, int pos);
int				place_z_horizontal(long **field, int field_size, int pos);
int				place_s_vertical(long **field, int field_size, int pos);
int				place_s_horizontal(long **field, int field_size, int pos);
int				place_l_vertical_up(long **field, int field_size, int pos);
int				place_l_vertical_down(long **field, int field_size, int pos);
int				place_l_horizontal_right(long **field, int field_size, int pos);
int				place_l_horizontal_left(long **field, int field_size, int pos);
int				place_j_vertical_up(long **field, int field_size, int pos);
int				place_j_vertical_down(long **field, int field_size, int pos);
int				place_j_horizontal_right(long **field, int field_size, int pos);
int				place_j_horizontal_left(long **field, int field_size, int pos);
int				place_t_up(long **field, int field_size, int pos);
int				place_t_right(long **field, int field_size, int pos);
int				place_t_left(long **field, int field_size, int pos);
int				place_t_down(long **field, int field_size, int pos);

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
**One tetro information
*/
typedef struct	s_tetro
{
	t_tetro_id	tetro_id;
	int			pos;
}				t_tetro;

typedef int		(*place_func)(long **field, int field_size, int pos);

typedef struct	s_place_figure_functions
{
	t_tetro_id	tetro_id;
	void		(*place_func)(long **field, int field_size, int pos);
}				t_place_figure_functions;

/*
**must to be deleted before realise (usage in file "get_tetro_id.c")
*/

# define one '1'
# define zero '0'

int		read_one_tetro(const int fd);
int     get_tetro_id(const char *str);

#endif
