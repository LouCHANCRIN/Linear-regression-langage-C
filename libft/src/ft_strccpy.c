/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 23:19:19 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/04 23:40:02 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strccpy(char *str, char c, int last_char)
{
	int		a;
	char	*tmp;

	a = 0;
	while (str[a] != c && str[a] != '\0')
		a++;
	if (!(tmp = (char*)malloc(sizeof(char) * (a + 1 + last_char))))
		return (NULL);
	a = 0;
	while (str[a] != c && str[a] != '\0')
	{
		tmp[a] = str[a];
		a++;
	}
	tmp[a] = str[a];
	tmp[a + last_char] = '\0';
	return (tmp);
}
