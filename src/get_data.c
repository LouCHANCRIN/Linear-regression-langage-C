#include "../include/linear_reg.h"

static void		test_theta(t_data data)
{
	int		a;
	char	*std;
	float	result;
	float	*user_data;

	if (!(user_data = (float*)malloc(sizeof(float) * (data.col - 1))))
	{
		free_data(data);
		return ;
	}
	while (1)
	{
		a = 0;
		ft_putstr("Enter the data to find the ");
		ft_putstr(data.name_value[data.col - 1]);
		ft_putstr(" (type exit to quit the programm)\n");
		while (a < data.col - 1)
		{
			ft_putstr(data.name_value[a]);
			ft_putstr(" : ");
			std = ft_read_std('\n');
			if (ft_strcmp(std, "exit") == 0)
			{
				free(user_data);
				return ;
			}
			user_data[a] = atof(std);
			free(std);
			a++;
		}
		a = 1;
		result = data.theta[0];
		while (a < data.col)
		{
			result += data.theta[a] * user_data[a - 1];
			a++;
		}
		printf("\n%s : %f.\n\n", data.name_value[data.col - 1], result);
	}
	free(user_data);
}

static t_data	get_data(int fd)
{
	int		a;
	char	buf[2];
	char	*str;
	t_data	data;

	data = init_data();
	if (!(str = (char*)malloc(sizeof(char))))
		return (data);
	str[0] = '\0';
	while ((a = read(fd, buf, 1)) > 0) //reading file
	{
		buf[a] = '\0';
		str = ft_strjoinfree(str, buf);
		if (data.line == 0 && buf[a - 1] == ',')
			data.col++;
		if (buf[a - 1] == '\n')
			data.line++;
		if (buf[a - 1] == '\0')
		{
			write(1, "Binary file are not alowed\n", 27);		
			return (data);
		}
	}
	if (data.line == 0 || data.col == 0)
		return (data);
	data.col++;
	data.line--;
	data = mat_fill_matrix(data, str, ','); //filling structure using str,
	free(str);								//data are separated by ','
	return (data);
}

static void		print_theta(t_data data)
{
	for (int i = 0; i < data.col; i++)
	{
		ft_putstr("	theta[");
		ft_putnbr(i);
		ft_putstr("] = ");
		printf("%f\n", data.theta[i]);
	}
}

static t_data	main2(t_data data)
{
	if (!(data.theta = (float*)malloc(sizeof(float) * data.col)))
		return (data);
	if (!(data.temp = (float*)malloc(sizeof(float) * data.col)))
		return (data);
	for (int a = 0; a < data.col; a++)
	{
		data.theta[a] = 0.0;
		data.temp[a] = 0.0;
	}
//	mat_print_data(data);
	data = scale_data(data);
	data = linear_reg(data);
	ft_putstr("\nBefore scaling :\n");
	print_theta(data);
	data = scale_theta(data);
	ft_putstr("\nAfter scaling :\n");
	print_theta(data);
	return (data);
}

int				main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac < 2)
	{
		write(1, "You need to enter a data set\n", 29);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) <= 0)
	{
		write(1, "File opening failed\n", 20);
		return (0);
	}
	data = get_data(fd);
	close(fd);
	if (data.line == 0 || data.col == 0)
		return (free_data(data));
	data = main2(data);
	test_theta(data);
	free_data(data);
	return (0);
}
