/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_vertical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:22:42 by dmelessa          #+#    #+#             */
/*   Updated: 2019/03/20 01:22:42 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** #
** ##
**  #
*/
int		place_s_vertical(long *field, int field_size, int pos)
{
	int 	column;
	int 	row;
	
	if (pos >= (field_size * (field_size - 2) - 1))
		return (-1);
	row = pos % field_size;
	if (row == field_size - 1)
		return (0);
	column = pos / field_size;
	if (check_bit(*(field + column), row)
		&& check_bit(*(field + column + 1), row)
		&& check_bit(*(field + column + 1), row + 1)
		&& check_bit(*(field + column + 2), row + 1))
	{
		set_bit(*(field + column), row);
		set_bit(*(field + column + 1), row);
		set_bit(*(field + column + 1), row + 1);
		set_bit(*(field + column + 2), row + 1);
		return (1);
	}
	return (0);
}

void	del_s_vertical(long *field, int size, int pos)
{
	int column;
	int row;

	column = pos / size;
	row = pos % size;
	zero_bit(*(field + column), row);
	zero_bit(*(field + column + 1), row);
	zero_bit(*(field + column + 1), row + 1);
	zero_bit(*(field + column + 2), row + 1);
}

void	out_s_vertical(char **field, int pos, char c, int field_size)
{
    int 	column;
	int 	row;

    row = pos / field_size;
	column = pos % field_size;
    field[row][column] = c;
    field[row + 1][column] = c;
    field[row + 1][column + 1] = c;
    field[row + 2][column + 1] = c;
}