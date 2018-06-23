/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_std.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 20:02:04 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/23 20:14:39 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_read_std(char stop_read)
{
	int		a;
	char	buf[2];
	char	*str;

	if (!(str = (char*)malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
	while ((a = read(0, buf, 1)) > 0 && buf[a - 1] != stop_read)
	{
		buf[a] = '\0';
		str = ft_strjoinfree(str, buf);
	}
	return (str);
}
