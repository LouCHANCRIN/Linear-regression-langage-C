#include "../include/linear_reg.h"

t_data		init_data(void)
{
	char	*str;
	t_data	data;

	write(1, "Enter the learning rate alpha\n", 30);
	str = ft_read_std('\n');
	data.alpha = atof(str);
	free(str);
	write(1, "Enter the number of iterations\n", 31);
	str = ft_read_std('\n');
	data.num_iters = atof(str);
	free(str);
	data.col = 0;
	data.line = 0;
	data.data = NULL;
	data.result = NULL;
	data.theta = NULL;
	data.temp = NULL;
	data.min = NULL;
	data.max = NULL;
	data.moy = NULL;
	data.name_value = NULL;
	return (data);
}
