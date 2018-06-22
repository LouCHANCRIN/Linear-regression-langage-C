#ifndef LINEAR_REG_H
# define LINEAR_REG_H
# include "../libft/include/libft.h"
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct	s_data
{
	float		**data;
	float		*result;
	float		*theta;
	float		*temp;
	float		*min;
	float		*max;
	float		*moy;
	float		alpha;
	int			num_iters;
	int			line;
	int			col;
}				t_data;

int				free_data(t_data data);
void			mat_print_data(t_data data);
t_data			linear_reg(t_data data);
t_data			scale_data(t_data data);
t_data			scale_theta(t_data data);
t_data			mat_fill_matrix(t_data data, char *str, char separator);

#endif
