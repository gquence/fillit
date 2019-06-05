/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_vertical_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <dmelessa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:22:16 by dmelessa          #+#    #+#             */
/*   Updated: 2019/04/15 14:19:53 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**  #
**  #
** ##
*/

int		place_j_vertical_down(long *field, int field_size, int pos)
{
	int column;
	int row;

	if (pos >= (field_size * (field_size - 2)))
		return (-1);
	row = pos % field_size;
	if (row == 0)
		return (0);
	column = pos / field_size;
	if (CHECK_BIT(*(field + column), row)
		&& CHECK_BIT(*(field + column + 1), row)
		&& CHECK_BIT(*(field + column + 2), row - 1)
		&& CHECK_BIT(*(field + column + 2), row))
	{
		SET_BIT(*(field + column), row);
		SET_BIT(*(field + column + 1), row);
		SET_BIT(*(field + column + 2), row - 1);
		SET_BIT(*(field + column + 2), row);
		return (1);
	}
	return (0);
}

void	del_j_vertical_down(long *field, int size, int pos)
{
	int column;
	int row;

	column = pos / size;
	row = pos % size;
	ZERO_BIT(*(field + column), row);
	ZERO_BIT(*(field + column + 1), row);
	ZERO_BIT(*(field + column + 2), row - 1);
	ZERO_BIT(*(field + column + 2), row);
}

void	out_j_vertical_down(char **field, int pos, char c, int field_size)
{
	int	column;
	int row;

	row = pos / field_size;
	column = pos % field_size;
	field[row][column] = c;
	field[row + 1][column] = c;
	field[row + 2][column] = c;
	field[row + 2][column - 1] = c;
}
