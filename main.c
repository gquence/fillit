#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/*возврат:	1 - строка соответствует всем требованиям, все действия выполнены
		0 - строка соответвуется всем требованиям, ошибка в выделении памяти
		-1 - строка или число не соответствуют каким-либо требованиям
*/

typedef enum	e_tetra_id
{
	error				= 0,
	l_horizontal_right		= 1,
	j_vertical_down			= 2,
	t_left				= 3,
	z_vertical			= 4,
	t_up				= 5,
	s_horizontal			= 6,
	i_vertical			= 7,
	l_vertical_down			= 8,
	s_vertical			= 9,
	t_right				= 10,
	j_horizontal_left		= 11,
	l_vertical_up			= 12,
	z_horizontal			= 13,
	j_vertical_up			= 14,
	quad				= 15,
	j_horizontal_right		= 16,
	t_down				= 17,
	l_horizontal_left		= 18,
	i_horizontal			= 19
}		t_tetro_id;

unsigned short int	tetra_value[20] = 
{0, 11776, 17600, 19520, 19584,
19968, 27648, 34952, 35008, 35904,
35968, 36352, 50240, 50688, 51328,
52224, 57856, 58368, 59392, 61440};
/*
void	init_tetra_value()
{
tetra_value[0] = 0;
tetra_value[1] = 11776;
tetra_value[2] = 17600;
tetra_value[3] = 19520;
tetra_value[4] = 19584;
tetra_value[5] = 19968;
tetra_value[6] = 27648;
tetra_value[7] = 34952;
tetra_value[8] = 35008;
tetra_value[9] = 35904;
tetra_value[10] = 35968;
tetra_value[11] = 36352;
tetra_value[12] = 50240;
tetra_value[13] = 50688;
tetra_value[14] = 51328;
tetra_value[15] = 52224;
tetra_value[16] = 57856;
tetra_value[17] = 58368;
tetra_value[18] = 59392;
tetra_value[19] = 61440;
}*/
int	ft_strcountchr(const char *str, int c)
{
	int result;

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

int	get_tetra_id(unsigned short int number, size_t prev_bb, size_t prev_hb, size_t b_border, size_t h_border)
{
	ft_putnbr((int)tetra_value[((h_border - b_border) / 2)]);
	ft_putnbr((int)((h_border - b_border) / 2));
	write(1, "--\n", 3);
	if (prev_bb == b_border && prev_hb == h_border)
		return (0);

	if (tetra_value[(int)((h_border - b_border) / 2)] < number)
		return (get_tetra_id(number, b_border, h_border, (int)((h_border - b_border) / 2), h_border));

	if (tetra_value[(int)((h_border - b_border) / 2)] > number)
		return (get_tetra_id(number, b_border, h_border, b_border, (int)((h_border - b_border) / 2)));

	return ((int)((h_border - b_border) / 2));
}

int	ft_stoi_bit(const char *str, unsigned short int *number)
{
	int		len;
	int		skipped;

	if (!number || !str || !*str)
		return (-1);
	*number = 0;
	len = ft_strlen(str);
	if (len != 16 || ft_strcountchr(str, (int)one) + ft_strcountchr(str, (int)zero) != len)
		return (-1);
	skipped = count_skip_columns(str) + count_skip_rows(str) * 4;
	str += skipped;
	while (*str)
	{
		*number <<= 1;
		if (*str == one)
			*number += 1;
		
		str++;
	}
	*number <<= skipped;
	return (1);
}



int	main()
{
	char	*str = "0000000000110011";
	unsigned short	int	numb;
	
//	init_tetra_value();
	printf("==%d==\n",ft_stoi_bit(str, &numb));
	printf("%d\n", numb);
	for (int i = 0; i < 20; i++)
	{
		printf("%d\t", tetra_value[i]);
	}
	printf("\n%d\n", get_tetra_id(numb, 0, 0, 0, 20));
	return (0);
}
/*
int main(int ac, char **av)
{
	int		fd;
	char	line[17];
	char	*buf;
	int		result;

	if (ac != 2)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (-2);
	line[16] = 0;
	while (get_next_line(fd, &buf) == 1 && ft_strlen(buf) == 4)
	{
		line = ft_strcat(line, buf);
		free(buf);
	}
	if (ft_stoi_bit(line, &result))
	{
		
	}
}*/
