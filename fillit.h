#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"

# define one '1'
# define zero '0'

int	count_skip_columns(const char *str);
int	count_skip_rows(const char *str);
int	ft_stoi_bit(const char *str, unsigned short int *number);

#endif
