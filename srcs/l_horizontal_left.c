/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_horizontal_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:22:27 by dmelessa          #+#    #+#             */
/*   Updated: 2019/03/20 01:22:27 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ###
** #
*/
int		place_l_horizontal_left(long *field, int field_size, int pos)
{
	int 	column;
	int 	row;
	
	if (pos >= (field_size * (field_size - 1) - 2))
		return (-1);
	row = pos % field_size;
	if (row == field_size - 1 || row == field_size - 2)
		return (0);
	column = pos / field_size;	
	if (check_bit(*(field + column), row)
		&& check_bit(*(field + column), row + 1)
		&& check_bit(*(field + column), row + 2)
		&& check_bit(*(field + column + 1), row))
	{
		set_bit(*(field + column), row);
		set_bit(*(field + column), row + 1);
		set_bit(*(field + column), row + 2);
		set_bit(*(field + column + 1), row);
		return (1);
	}
	return (0);
}

void	del_l_horizontal_left(long *field, int size, int pos)
{
	int column;
	int row;

	column = pos / size;
	row = pos % size;
	zero_bit(*(field + column), row);
	zero_bit(*(field + column), row + 1);
	zero_bit(*(field + column), row + 2);
	zero_bit(*(field + column + 1), row);
}

void	out_l_horizontal_left(char **field, int pos, char c, int field_size)
{
    int 	column;
	int 	row;

    row = pos / field_size;
	column = pos % field_size;
    field[row][column] = c;
    field[row + 1][column] = c;
    field[row][column + 1] = c;
    field[row][column + 2] = c;
}
