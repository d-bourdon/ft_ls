/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_taille_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 12:22:11 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/17 12:55:52 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	max_taille_lst(t_liste *lst, int *max)
{
	t_liste	*tmp;
	int		tmpmax;

	tmpmax = 0;
	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp->type != 99)
		{
			tmpmax = ft_intlen(tmp->lien);
			if (tmpmax > max[0])
				max[0] = tmpmax;
			tmpmax = ft_strlen(tmp->nom_u);
			if (tmpmax > max[1])
				max[1] = tmpmax;
			tmpmax = ft_strlen(tmp->groupe_u);
			if (tmpmax > max[2])
				max[2] = tmpmax;
			tmpmax = ft_intlen(tmp->taille);
			if (tmpmax > max[3])
				max[3] = tmpmax;
		}
		tmp = tmp->next;
	}
}

void	ft_putnbr_tab(int nb, int max)
{
	int		tmp;
	int		i;

	tmp = 0;
	i = 0;
	tmp = ft_intlen(nb);
	while (i++ < (max - tmp))
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
