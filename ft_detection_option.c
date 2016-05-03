/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:30:08 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/03 16:48:38 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ft_detection_option(char *str, int *option)
{
	int		i;

	i = 1;
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == 'l')
			option[0] = 1;
		else if (str[i] == 'a')
			option[1] = 1;
		else if (str[i] == 'R')
			option[2] = 1;
		else if (str[i] == 'r')
			option[3] = 1;
		else if (str[i] == 't')
			option[4] = 1;
		else
			ft_erreur(&(str[i]), 1);
		i++;
	}
	return (option);
}
