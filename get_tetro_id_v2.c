#include <stdio.h>
#include "fillit.h"



int		count_skip_rows(const char *str)
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

int		count_skip_columns(const char *str)
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
			return(-1);
	}
	return (count);
}
/*
int main()
{
	char *str = "0000000000110011";
	printf("%d\\%d", count_skip_rows(str), count_skip_columns(str));
	printf("\n2%s\n", str);
	str = str + count_skip_rows(str) *4 + count_skip_columns(str);
	printf("2%s", str);
	return (0);
}*/
