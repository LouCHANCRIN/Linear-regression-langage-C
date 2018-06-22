#include "../include/linear_reg.h"

void		mat_print_data(t_data data)
{
	int		c;
	int		l;

	c = 0;
	l = 0;
	while (l < data.line)
	{
		while (c < data.col)
		{
			printf("% 12f   ", data.data[c][l]);
			c++;
		}
		c = 0;
		l++;
		printf("\n");
	}
}
