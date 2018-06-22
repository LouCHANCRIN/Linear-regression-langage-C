/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 17:44:41 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/21 17:54:28 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

int		ft_is_int(char *str, int signe, char c)
{
	int			a;
	long long	b;

	if (!str)
		return (0);
	a = signe;
	b = ft_atoll(str);
	if (signe == 1)
		if (str[0] != '-' && str[0] != '+' && !(str[0] >= 48 && str[0] <= 57))
			return (0);
	while (str[a] != '\0' && str[a] != c)
	{
		if (!(str[a] >= 48 && str[a] <= 57))
			return (0);
		a++;
	}
	if (b < -2147483648 || b > 2147483647 || a > 11 ||
			(a > 0 && !(str[a - 1] >= 48 && str[a - 1] <= 57)))
		return (0);
	return (1);
}
