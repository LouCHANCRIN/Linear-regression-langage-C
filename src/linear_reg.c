#include "../include/linear_reg.h"

static float	hypothese(t_data data, int c, int l)
{
	int		som = 0;

	for (int j = 0; j < data.col; j++)
	{
		som += (data.theta[j] * data.data[j][l]);
	}
	som -= data.result[l];
	som *= data.data[c][l];
	return (som);
}


static float	cost(t_data data, int c)
{
	int		som = 0;

	for (int l = 0; l < data.line; l++)
		som += hypothese(data, c, l);
	return (data.theta[c] - ((data.alpha * som)));
}

t_data			linear_reg(t_data data)
{
	for (int n = 0; n < data.num_iters; n++)
	{
		for (int c = 0; c < data.col; c++)
			data.temp[c] = cost(data, c);
		for (int c = 0; c < data.col; c++)
			data.theta[c] = data.temp[c];
	}
	return (data);
}
