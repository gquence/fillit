#include <stdio.h>
#include "fillit.h"

int		count_skip_rows(char *str)
{
	int count;

	count = 0;
	while (*str && *str == zero)
	{
		count++;
		str++;
	}
	return (count / 4);
}

int		count_skip_columns(char *str)
{
	int	count;
	int	i;
	int	multiplier;

	count = 0;
	i = 0;
	multiplier = 4;
	while (*(str + (i * multiplier + count)))
	{
		if (*(str + (i * multiplier + count)) == one)
			break ;
		i++;
		if (i == 4)
		{
			i = 0;
			count++;
		}
		if (count == 4)
			reutrn(-1);
	}
	return (count);
}

int main()
{
	return (0);
}
