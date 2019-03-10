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
char	zero = '0';
char	one = '1';

typedef enum	e_tetra_id
{
	error			= 0,
	quad			= 1,
	i_vertical		= 2,
	i_horizontal		= 4,
	z_vertical		= 8,
	z_horizontal		= 16,
	s_vertical		= 32,
	s_horizontal		= 64,
	l_vertical_up		= 128,
	l_vertical_down		= 256,
	l_horizontal_right	= 512,
	l_horizontal_left	= 1024,
	j_vertical_up		= 2048,
	j_vertical_down		= 4096,
	j_horizontal_right	= 8192,
	j_horizontal_left	= 16384,
	t_up			= 32768,
	t_right			= 65536,
	t_down			= 131072,
	t_left			= 262144
}		t_tetro_id;


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

/**/

int	ft_stoi_bit(const char *str, int *number)
{
	int		result;
	int		count;
	size_t		len;
	size_t		first_entry;

	if (!number || !str || !*str)
		return (-1);
	*number = 0;
	len = ft_strlen(str);
	if (len != 16 || ft_strcountchr(str, one) + ft_strcountchr(str, zero) != len)
		return (-1);
	count = 0;
	first_entry = 0;
	while (*str && (*str == one || *str == zero))
	{
		if (!count && *str == zero)
			first_entry++;
		else if (*str == one)
		{
			(*number) <<= 1;
			(*number)++;
			count++;
		}
		else if (*(str + 1))
		{
			(*number) <<= 1;
		}
		str++;
	}
	if (first_entry)
		(*number) <<= first_entry;
	if (count != 4)
	{
		*number = 0;
		return (-1);
	}
	return (1);
}
int	main()
{
	char	*str = "0000111100000000";
	int	numb;

	printf("==%d==\n",ft_stoi_bit(str, &numb));
	printf("%d", numb);
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
