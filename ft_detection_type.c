/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:08:43 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/10 14:51:36 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_detection_type(unsigned char type)
{
	printf("%c -- ", type);
	if (type == 4)
		return ('d');
	if (type == 8)
		return ('-');
	if (type == 10)
		return('l');
	return ('?');
}
