/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:48:41 by paim              #+#    #+#             */
/*   Updated: 2015/11/30 00:47:00 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		val;
	char	check;

	i = 0;
	val = 0;
	check = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		check = 1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		val = val * 10;
		val = (str[i] - 48) + val;
		i++;
	}
	if (check)
		val = val * -1;
	return (val);
}
