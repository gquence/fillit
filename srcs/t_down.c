/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_down.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:22:45 by dmelessa          #+#    #+#             */
/*   Updated: 2019/03/20 01:22:45 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ###
**  #
*/
int		place_t_down(long *field, int field_size, int pos)
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
		&& check_bit(*(field + column + 1), row + 1)
		&& check_bit(*(field + column), row + 2))
	{
		set_bit(*(field + column), row);
		set_bit(*(field + column), row + 1);
		set_bit(*(field + column + 1), row + 1);
		set_bit(*(field + column), row + 2);
		return (1);
	}
	return (0);
}

void	del_t_down(long *field, int size, int pos)
{
	int column;
	int row;

	column = pos / size;
	row = pos % size;
	zero_bit(*(field + column), row);
	zero_bit(*(field + column), row + 1);
	zero_bit(*(field + column + 1), row + 1);
	zero_bit(*(field + column), row + 2);
}

void	out_t_down(char **field, int pos, char c, int field_size)
{
    int 	column;
	int 	row;

    row = pos / field_size;
	column = pos % field_size;
    field[row][column] = c;
    field[row][column + 1] = c;
    field[row][column + 2] = c;
    field[row + 1][column + 1] = c;
}
