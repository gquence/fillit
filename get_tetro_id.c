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
//second and third - изначальные границы 
static int		find_tetro_id(const unsigned short int number, size_t b_border, size_t h_border)
{
	size_t	prev_bb;
	size_t	prev_hb;
	int		pos;

	while (prev_bb != b_border || prev_hb != h_border)
	{
		pos = (int)((h_border - b_border) / 2) + b_border;
		if (tetra_value[pos] == number)
			return (pos);
		if (tetra_value[pos] < number)
		{
			prev_bb = b_border;
			prev_hb = h_border;
			b_border = pos;
		}
		if (tetra_value[pos] > number)
		{
			prev_bb = b_border;
			prev_hb = h_border;
			h_border = pos;
		}		
	}
	return ((int)error);
}


int     get_tetro_id(const char *str)
{
	int					number;
	int					len;
	int					skipped;

	if (!str || !*str)
		return ((int)error);
	number = 0;
	len = strlen(str);
	if (len != 16 || ft_strcountchr(str, (int)one) + ft_strcountchr(str, (int)zero) != len)
		return ((int)error);
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
	return (find_tetro_id(number, 1, 20));
}

int		convert_to_tetro(const char *line, char *ptetro)
{
	int		i;
	char	*tetro;

	i = 0;
	tetro = ptetro;
	while (i != 4)
	{
		if (line[i] != (char)zero && line[i] != (char)one)
			return (0);
		tetro[i] = line[i];
		i++;
	}
	if (line[i] != '\n')
		return (0);
	return(1);

}

int		check_ret(const int ret, int *n_koef, char *line)
{
	if (!ret && !(*n_koef))
		return ((int)end);
	if (ret != 21 && ret != 20)
		return ((int)error);
	if (ret == 21)
	{
		if (line[20] != '\n')
			return ((int)error);
		*n_koef = 1;
	}
	else
		*n_koef = 0;
	return ((int)start);
}

int		read_one_tetro(const int fd)
{
	char				line[22];
	char				tetro_line[17];
	int					line_count;
	int					ret;
	static int				n_koef;

	ft_memset((void *)line, 0, 22);
	ft_memset((void *)tetro_line, 0, 17);
	ret = read(fd, &line, 21);
	if ((line_count = check_ret(ret, &n_koef, line)) == (int)end)
		return ((int)end);
	if (line_count == (int)error)
		return ((int)error);
	line_count = 0;
	while (line_count != 4)
	{
		if (!convert_to_tetro((line + (line_count * 5)), (tetro_line + (line_count * 4))))
			return ((int)error);
		line_count++;
	}
	return (get_tetro_id(tetro_line));
}
