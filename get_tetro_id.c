#include "fillit.h"


unsigned short int	tetra_value[20] = 
{
	0,
	11776,
	17600,
	19520,
	19584,
	19968,
	27648,
	34952,
	35008,
	35904,
	35968,
	36352,
	50240,
	50688,
	51328,
	52224,
	57856,
	58368,
	59392,
	61440
};

//***счётчик символов в строке (для проверки верности символов)
int	ft_strcountchr(const char *str, int c)
{
	int				result;

	if (!str)
		return (-1);
	result = 0;
	while(*str)
	{
		if (*str == c)
			result++;
		str++;
	}
	return (result);
}

static int		count_skip_rows(const char *str)
{
	int					count;

	count = 0;
	while (*str && *str == zero)
	{
		count++;
		str++;
	}
	return (count / 4);
}

static int		count_skip_columns(const char *str)
{
	int					count;
	int					i;
	int					multiplier;

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

//***ищет номер тетромино в массиве выше
//first arg - число с кодом тетромино,
//second and third args - args for checking the infinity recursive(уходит в бесконечную рекурсию, если number находится между какими-то значениями),
//fourth and fifth - изначальные границы 
static int		find_tetro_id(unsigned short int number, size_t prev_bb, size_t prev_hb, size_t b_border, size_t h_border)
{
	int					pos;

	pos = (int)((h_border - b_border) / 2) + b_border;
	if (prev_bb == b_border && prev_hb == h_border)
		return (-1);
	if (tetra_value[pos] < number)
		return (find_tetro_id(number, b_border, h_border, pos, h_border));
	if (tetra_value[pos] > number)
		return (find_tetro_id(number, b_border, h_border, b_border, pos));
	return (pos);
}


int     get_tetro_id(const char *str)
{
	int					number;
	int					len;
	int					skipped;

	if (!str || !*str)
		return (-1);
	number = 0;
	len = strlen(str);
	if (len != 16 || ft_strcountchr(str, (int)one) + ft_strcountchr(str, (int)zero) != len)
		return (-1);
	skipped = count_skip_columns(str) + count_skip_rows(str) * 4;
	str += skipped;
	while (*str)
	{
		number <<= 1;
		if (*str == one)
			number += 1;
		str++;
	}
	number <<= skipped;
	return (find_tetro_id(number, 0, 0, 1, 20));
}

int		read_one_tetro(const int fd)
{
	char				line[17];
	char				*str;
	short unsigned int	len;
	int					ret;

	len = 0;
	while ((ret = get_next_line(fd, &str)) == 1)
	{
		if (ft_strlen(str) != 4)
				if (len == 4)
					break ;
				else
				{
					free(str);
					return (-1);
				}
		ft_strcat(line, str);
		free(str);
		if (len > 4)	
			return (-1);
		len++;
	}
	if (ret == 0)
		return (20);
	ft_strcat(line, str);
	line[16] = 0;
	return (get_tetro_id(line));
}