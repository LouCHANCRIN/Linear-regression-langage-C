#include "../include/linear_reg.h"

static t_data	fill_matrix(char *str, t_data data, char separator)
{
	int		a;
	int		c;
	int		l;

	c = 2;
	l = 0;
	a = ft_strclen(str, '\n') + 1;
	data.data[0][0] = 1.0;
	data.data[1][0] = atof(&str[a]);
	while (str[a] != '\0')
	{
		if (str[a] == separator && str[a + 1] != '\0')
		{
			if (c == data.col)
				data.result[l] = atof(&str[a + 1]);
			else
				data.data[c][l] = atof(&str[a + 1]);
			c++;
		}
		if (str[a] == '\n')
		{
			c = 2;
			l++;
			data.data[0][l] = 1.0;
			if (str[a + 1] != '\0')
				data.data[1][l] = atof(&str[a + 1]);
		}
		a++;
	}
	return (data);
}

t_data			mat_fill_matrix(t_data data, char *str, char separator)
{
	int		a;
	int		c;
	int		n;

	a = 0;
	c = 0;
	if (!(data.data = (float**)malloc(sizeof(float*) * (data.col))))
		return (data);
	if (!(data.name_value = (char**)malloc(sizeof(char*) * (data.col))))
		return (data);
	n = ft_strclen(str, '\n');
	while (str[c] != '\n' && str[a] != '\0')
	{
		if (c == 0 || (str[c] == separator && (c = c + 1)))
		{
			if (ft_strclen(&str[c], separator) + c > n)
				data.name_value[a] = ft_strccpy(&str[c], '\n', 0);
			else
				data.name_value[a] = ft_strccpy(&str[c], separator, 0);
			a++;
		}
		c++;
	}
	c = 0;
	while (c < data.col)
	{
		if (!(data.data[c] = (float*)malloc(sizeof(float) * data.line)))
			return (data);
		c++;
	}
	if (!(data.result = (float*)malloc(sizeof(float) * data.line)))
		return (data);
	data = fill_matrix(str, data, separator);
	return (data);
}
