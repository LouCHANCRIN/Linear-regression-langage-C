#include "../include/linear_reg.h"

int			free_data(t_data data)
{
	int		a;

	a = 0;
	if (data.data)
	{
		while (a < data.col)
		{
			free(data.data[a]);
			a++;
		}
		free(data.data);
	}
	if (data.name_value)
	{
		a = 0;
		while (a < data.col)
		{
			if (data.name_value[a])
				free(data.name_value[a]);
			a++;
		}
		free(data.name_value);
	}
	if (data.result)
		free(data.result);
	if (data.theta)
		free(data.theta);
	if (data.temp)
		free(data.temp);
	if (data.min)
		free(data.min);
	if (data.max)
		free(data.max);
	if (data.moy)
		free(data.moy);
	return (0);
}
