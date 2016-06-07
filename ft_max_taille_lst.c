/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_taille_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:22:11 by dbourdon          #+#    #+#             */
/*   Updated: 2016/06/06 18:03:21 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*max_taille_lst(t_liste *lst, int *max, int tmpmax)
{
	t_liste	*tmp;

	tmp = lst;
	while (tmp && tmp->type != 9)
	{
		tmpmax = ft_intlen(tmp->lien);
		max[0] = (tmpmax > max[0]) ? tmpmax : max[0];
		tmpmax = ft_strlen(tmp->nom_u);
		max[1] = (tmpmax > max[1]) ? tmpmax : max[1];
		tmpmax = ft_strlen(tmp->groupe_u);
		max[2] = (tmpmax > max[2]) ? tmpmax : max[2];
		tmpmax = ft_intlen(tmp->taille);
		max[3] = (tmpmax > max[3]) ? tmpmax : max[3];
		max[4] = max[4] + tmp->nb_bloc;
		tmpmax = ft_intlen(tmp->minor);
		max[5] = (tmpmax > max[5]) ? tmpmax : max[5];
		tmpmax = ft_intlen(tmp->major);
		max[6] = (tmpmax > max[6]) ? tmpmax : max[6];
		if (tmp->type == 'c' || tmp->type == 'b')
			max[3] = ((max[5] + max[6]) != 0) ? (max[5] + max[6]) + 3 : max[3];
		tmp = tmp->next;
	}
	return (max);
}

void	ft_putnbr_tab(int nb, int max)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
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
	ft_putstr(str);
	while (i++ < (max - tmp))
		write(1, " ", 1);
}
