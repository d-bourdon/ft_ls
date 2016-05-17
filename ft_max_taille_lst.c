/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_taille_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:22:11 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/17 16:07:14 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*max_taille_lst(t_liste *lst, int *max)
{
	t_liste	*tmp;
	int		tmpmax;

	tmpmax = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->type != 99)
		{
			tmpmax = ft_intlen(tmp->lien);
			if (tmpmax > max[0])
				max[0] = tmpmax;
		//	tmpmax = ft_strlen(tmp->nom_u);
		//	if (tmpmax > max[1])
		//		max[1] = tmpmax;
			tmpmax = ft_strlen(tmp->groupe_u);
			if (tmpmax > max[2])
				max[2] = tmpmax;
			tmpmax = ft_intlen(tmp->taille);
			max[4] = max[4] + tmp->nb_bloc;
			if (tmpmax > max[3])
				max[3] = tmpmax;
		}
		tmp = tmp->next;
		//printf("MAX [0] = %d\n", max[0]);
	}
	return (max);
}

void	ft_putnbr_tab(int nb, int max)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
//	printf("Max = %d\n", max);
	tmp = ft_intlen(nb);
	while (i++ < ((max - tmp) + 1))
		write(1, " ", 1);
	ft_putnbr(nb);
}

void	ft_putstr_tab(char *str, int max)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	tmp = ft_strlen(str);
	while (i++ < (max - tmp))
		write(1, " ", 1);
	ft_putstr(str);
}
