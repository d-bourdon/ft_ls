/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heure.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:33:16 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/31 14:21:30 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_heure(time_t heure)
{
	char	*sortie;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(ctime(&heure), ' ');
	tmp[3][5] = '\0';
	sortie = ft_strdup(tmp[1]);
	sortie = ft_strjoinfree(sortie, " ", 1);
	if (ft_strlen(tmp[2]) == 1)
		sortie = ft_strjoinfree(sortie, " ", 1);
	sortie = ft_strjoinfree(sortie, tmp[2], 1);
	sortie = ft_strjoinfree(sortie, " ", 1);
	sortie = ft_strjoinfree(sortie, tmp[3], 1);
	while (i < 5)
		free(tmp[i++]);
	free(tmp);
	return (sortie);
}
