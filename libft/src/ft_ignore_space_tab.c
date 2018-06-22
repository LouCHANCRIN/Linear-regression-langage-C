/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ignore_space_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:47:13 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/19 23:03:34 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_ignore_space_tab(char *str, int a)
{
	int		len;

	len = ft_strlen(str);
	if (!str)
		return (-1);
	while (a < len && (str[a] == 32 || str[a] == 9) && str[a] != '\0')
		a++;
	return (a);
}
