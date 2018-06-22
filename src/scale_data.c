#include "../include/linear_reg.h"

static t_data	scaled_data(t_data data)
{
	int		c;
	int		l;
	int		range;

	c = 1; //c = 1 so we don't scale the theta[0] row
	l = 0;
	while (c < data.col)
	{
		range = data.max[c] - data.min[c];
		while (l < data.line)
		{
			data.data[c][l] = (data.data[c][l]) / range;
			l++;
		}
		l = 0;
		c++;
	}
	return (data);
}

t_data			scale_data(t_data data)
{
	int		c;
	int		l;

	c = 0;
	l = 0;
	if (!(data.min = (float*)malloc(sizeof(float) * data.col))) //saving min and max so 
		return (data);											//we can scale theta later
	if (!(data.max = (float*)malloc(sizeof(float) * data.col)))
		return (data);
	if (!(data.moy = (float*)malloc(sizeof(float) * data.col)))
		return (data);
	while (c < data.col)
	{
		data.min[c] = data.data[c][l];
		data.max[c] = data.data[c][l];
		data.moy[c] = 0;
		c++;
	}
	c = 1;
	while (c < data.col)
	{
		while (l < data.line)
		{
			if (data.data[c][l] < data.min[c])
				data.min[c] = data.data[c][l];
			if (data.data[c][l] > data.max[c])
				data.max[c] = data.data[c][l];
			data.moy[c] += data.data[c][l];
			l++;
		}
		data.moy[c] /= l;
		l = 0;
		c++;
	}
	return (scaled_data(data));
}

t_data			scale_theta(t_data data)
{
	for (int c = 1; c < data.col; c++) //c = 1 so we don't scale the theta[0] row
		data.theta[c] = data.theta[c] / (data.max[c] - data.min[c]);
	return (data);
}
