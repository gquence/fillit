/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_vertical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:21:44 by dmelessa          #+#    #+#             */
/*   Updated: 2019/03/20 01:21:44 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*	
**	#
**	#
**	#
**	#
*/	
int		place_i_vertical(long *field, int field_size, int pos)
{
	int 	column;
	int 	row;
	
	if (pos >= (field_size * (field_size - 3)))
		return (-1);
	column = pos / field_size;
	row = pos % field_size;	
	if (check_bit(*(field + column), row)
		&& check_bit(*(field + column + 1), row)
		&& check_bit(*(field + column + 2), row)
		&& check_bit(*(field + column + 3), row))
	{
		set_bit(*(field + column), row);
		set_bit(*(field + column + 1), row);
		set_bit(*(field + column + 2), row);
		set_bit(*(field + column + 3), row);
		return (1);
	}
	return (0);
}

void	del_i_vertical(long *field, int size, int pos)
{
	int column;
	int row;

	column = pos / size;
	row = pos % size;
	zero_bit(*(field + column), row);
	zero_bit(*(field + column + 1), row);
	zero_bit(*(field + column + 2), row);
	zero_bit(*(field + column + 3), row);
}

void	out_i_vertical(char **field, int pos, char c, int field_size)
{
    int 	column;
	int 	row;

    row = pos / field_size;
	column = pos % field_size;
    field[row][column] = c;
    field[row + 1][column] = c;
    field[row + 2][column] = c;
    field[row + 3][column] = c;
}