/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_horizontal_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <dmelessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:22:30 by dmelessa          #+#    #+#             */
/*   Updated: 2019/04/15 14:19:53 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**   #
** ###
*/

int		place_l_horizontal_right(long *field, int field_size, int pos)
{
	int column;
	int row;

	if (pos >= (field_size * (field_size - 1)))
		return (-1);
	row = pos % field_size;
	if (row == 0 || row == 1)
		return (0);
	column = pos / field_size;
	if (CHECK_BIT(*(field + column), row)
		&& CHECK_BIT(*(field + column + 1), row)
		&& CHECK_BIT(*(field + column + 1), row - 2)
		&& CHECK_BIT(*(field + column + 1), row - 1))
	{
		SET_BIT(*(field + column), row);
		SET_BIT(*(field + column + 1), row);
		SET_BIT(*(field + column + 1), row - 2);
		SET_BIT(*(field + column + 1), row - 1);
		return (1);
	}
	return (0);
}

void	del_l_horizontal_right(long *field, int size, int pos)
{
	int column;
	int row;

	column = pos / size;
	row = pos % size;
	ZERO_BIT(*(field + column), row);
	ZERO_BIT(*(field + column + 1), row);
	ZERO_BIT(*(field + column + 1), row - 2);
	ZERO_BIT(*(field + column + 1), row - 1);
}

void	out_l_horizontal_right(char **field, int pos, char c, int field_size)
{
	int	column;
	int row;

	row = pos / field_size;
	column = pos % field_size;
	field[row][column] = c;
	field[row + 1][column] = c;
	field[row + 1][column - 1] = c;
	field[row + 1][column - 2] = c;
}
