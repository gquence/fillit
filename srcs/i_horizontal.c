/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_horizontal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <dmelessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:21:39 by dmelessa          #+#    #+#             */
/*   Updated: 2019/04/15 14:19:55 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** ####
*/

int		place_i_horizontal(long *field, int field_size, int pos)
{
	int	column;
	int row;

	if (pos >= (field_size * field_size - 3))
		return (-1);
	row = pos % field_size;
	if (row >= field_size - 3 && row <= field_size - 1)
		return (0);
	column = pos / field_size;
	if (CHECK_BIT(*(field + column), row)
		&& CHECK_BIT(*(field + column), row + 1)
		&& CHECK_BIT(*(field + column), row + 2)
		&& CHECK_BIT(*(field + column), row + 3))
	{
		SET_BIT(*(field + column), row);
		SET_BIT(*(field + column), row + 1);
		SET_BIT(*(field + column), row + 2);
		SET_BIT(*(field + column), row + 3);
		return (1);
	}
	return (0);
}

void	del_i_horizontal(long *field, int size, int pos)
{
	int column;
	int row;

	column = pos / size;
	row = pos % size;
	ZERO_BIT(*(field + column), row);
	ZERO_BIT(*(field + column), row + 1);
	ZERO_BIT(*(field + column), row + 2);
	ZERO_BIT(*(field + column), row + 3);
}

void	out_i_horizontal(char **field, int pos, char c, int field_size)
{
	int	column;
	int	row;

	row = pos / field_size;
	column = pos % field_size;
	field[row][column] = c;
	field[row][column + 1] = c;
	field[row][column + 2] = c;
	field[row][column + 3] = c;
}
