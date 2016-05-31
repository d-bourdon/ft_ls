/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:14:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/31 14:20:56 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoinfree(char *s1, char *s2, int mode)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (mode == 1)
		free(s1);
	else if (mode == 2)
		free(s2);
	else
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}
