/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:40:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/17 13:00:33 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
int		max_nom_lst(t_liste *lst_f)
{
	t_liste	*tmp;
	int		i;
	int		taille;

	taille = 0;
	i = 0;
	tmp = lst_f;
	while (tmp && (tmp->type != 99))
	{
		i = ft_strlen(tmp->nom);
		if (i > taille)
			taille = i;
		tmp = tmp->next;
	}
	return (taille + 3);
}

void	ft_affichage_normal(t_liste *lst_f, int *option, int argc)
{
	int		i;
	int		j;
	int		maxnom;
	int		tmpnom;
	t_liste	*tmp;
	struct winsize	w;

	tmp = lst_f;
	option[1] = 1;
	maxnom = 0;
	tmpnom = 0;
	ioctl(0, TIOCGWINSZ, &w);
	i = 0;
	j = 0;
	if (argc < 3)
		lst_f = lst_f->next;
	while (lst_f && lst_f->next != NULL)
	{
		if (lst_f->type == 99)
		{
			if (argc > 2 || option[2] == 1)
			{
				ft_putchar('\n');
				ft_putstr(lst_f->nom);
				ft_putstr(":");
			}
			lst_f = lst_f->next;
		}
		else
		{
			maxnom = max_nom_lst(lst_f);
			while (lst_f && (lst_f->type != 99))
			{
				if (i == 0 || i < (w.ws_col / maxnom))
				{
					ft_putstr(lst_f->nom);
					tmpnom = ft_strlen(lst_f->nom);
					while (j++ < (maxnom - tmpnom))
						ft_putchar(' ');
					i++;
					j = 0;
					lst_f = lst_f->next;
				}
				else
				{
					ft_putchar('\n');
					i = 0;
				}
			}
		}
		ft_putchar('\n');
	}
}

void	ft_affichage_liste(t_liste *lst_f, int *option, int argc)
{
	int		max[4];

	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	max[3] = 0;
	max_taille_lst(lst_f, max);
	argc = 2;
	option[1] = 1;
	while (lst_f)
	{
		if (lst_f->type != 99)
		{
			ft_putchar(lst_f->type);
			ft_putstr(lst_f->droits);
			ft_putstr("  ");
			ft_putnbr_tab(lst_f->lien, max[0]);
			ft_putchar(' ');
			ft_putstr_tab(lst_f->nom_u, max[1]);
			ft_putchar(' ');
			ft_putchar(' ');
			ft_putstr_tab(lst_f->groupe_u, max[2]);
			ft_putchar(' ');
			ft_putnbr_tab(lst_f->taille, max[3]);
			ft_putchar(' ');
			ft_putstr(lst_f->date_heure);
			ft_putchar(' ');
			ft_putstr(lst_f->nom);
			ft_putchar('\n');
		}
		else
		{
			ft_putchar('\n');
			ft_putstr(lst_f->nom);
			ft_putstr(":\n");
		}
		lst_f = lst_f->next;
	}
}

void	ft_affichage(t_liste *lst_f, int *option, int argc)
{
//	int		taille[5];

//	ft_bzero(taille, 20);
	if (lst_f == NULL)
		ft_erreur("", 3);
	if (option[0] != 1)
		ft_affichage_normal(lst_f, option, argc);
	else
		ft_affichage_liste(lst_f, option, argc);
}
