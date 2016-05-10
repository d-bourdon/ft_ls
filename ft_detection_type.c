/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detection_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:08:43 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/10 16:48:49 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_detection_type(uint8_t type)
{
	if (type == DT_DIR)
		return ('d');
	if (type == DT_REG)
		return ('-');
	if (type == DT_LNK)
		return('l');
	printf("%u\n", type);
	return ('?');
}
