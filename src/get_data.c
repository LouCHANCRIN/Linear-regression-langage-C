#include "../include/linear_reg.h"

static t_data	get_data(int fd)
{
	int		a;
	char	buf[2];
	char	*str;
	t_data	data;

	data.col = 0;
	data.line = 0;
	data.min = NULL;
	data.max = NULL;
	data.moy = NULL;
	if (!(str = (char*)malloc(sizeof(char))))
		return (data);
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
	data = mat_fill_matrix(data, str, ','); //filling structure using str
	free(str);
	return (data);
}

t_data			main2(t_data data, char **av)
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
	data = scale_data(data);
	mat_print_data(data);
	data.alpha = atof(av[2]);
	data.num_iters = ft_atoi(av[3]);
	data = linear_reg(data);
	printf("\nBefore scaling :\n");
	for (int i = 0; i < data.col; i++)
		printf("	theta[%d] = %f\n", i, data.theta[i]);
	data = scale_theta(data);
	printf("\nAfter scaling :\n");
	for (int i = 0; i < data.col; i++)
		printf("	theta[%d] = %f\n", i, data.theta[i]);
	return (data);
}

int				main(int ac, char **av)
{
	int		a;
	int		fd;
	int		nb_rooms;
	float	size;
	float	price;
	t_data	data;

	a = 0;
	if (ac < 4)
	{
		write(1, "You need to enter a data set, a learning rate alpha and the number of iterations required\n", 90);
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
	data = main2(data, av);
	while (1)
	{
		printf("Enter the size of the house and the number of rooms (press control + c to exit the program)\n");
		scanf("%f", &size);
		scanf("%d", &nb_rooms);
		price = data.theta[0] + data.theta[1] * size + data.theta[2] * nb_rooms;
		printf("\nPrice : %f.\n", price);
	}
	free_data(data);
	return (0);
}
