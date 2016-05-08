/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:40:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/08 15:25:56 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_affichage_normal(t_liste *lst_f, int *option, int argc)
{
	int		i;

	if (option[0] == argc)
		exit(0);
	i = 0;

	while (lst_f->next != NULL)
	{
		while(i < 2 && lst_f->next != NULL)
		{
			ft_putstr(lst_f->nom);
			ft_putstr("    ");
			i++;
			lst_f = lst_f->next;
		}
		ft_putchar('\n');
		i = 0;
	}
}

void	ft_affichage(t_liste *lst_f, int *option, int argc)
{
	if (option[0] != 1)
		ft_affichage_normal(lst_f, option, argc);
	else
	{
		while (lst_f->next != NULL)
		{
			ft_putnbr(lst_f->type);
			ft_putchar(' ');
			ft_putstr(lst_f->droits);
			ft_putstr("  ");
			ft_putnbr(lst_f->lien);
			ft_putchar(' ');
			ft_putstr(lst_f->groupe_u);
			ft_putchar(' ');
			ft_putnbr(lst_f->taille);
			ft_putchar(' ');
			ft_putstr(lst_f->date_heure);
			ft_putchar('\n');
			lst_f = lst_f->next;
		}
	}
}
