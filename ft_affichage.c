/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:40:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/21 14:19:30 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_affichage_dossier(char *nom, int mode)
{
	if (mode == 2)
		ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr(nom);
	ft_putstr(":\n");
	return (0);
}

static int	ft_affichage_n2(int col, int max, t_liste **lst_f, int i)
{
	int		tmpnom;
	int		j;

	tmpnom = 0;
	j = 0;
	if (i == 0 || i < (col / max))
	{
		ft_putstr((*lst_f)->nom);
		tmpnom = ft_strlen((*lst_f)->nom);
		while (j++ < (max - tmpnom))
			ft_putchar(' ');
		i++;
		j = 0;
		*lst_f = (*lst_f)->next;
	}
	else
	{
		ft_putchar('\n');
		i = 0;
	}
	return (i);
}

void		ft_affichage_normal(t_liste *lst_f, int *option, int argc)
{
	int				i;
	int				maxnom;
	struct winsize	w;

	option[1] = 1;
	maxnom = 0;
	ioctl(0, TIOCGWINSZ, &w);
	i = 0;
	if (argc < 3)
		lst_f = lst_f->next;
	while (lst_f)
	{
		if (lst_f->type == 99)
		{
			if (argc > 2 || option[2] == 1)
				i = ft_affichage_dossier(lst_f->nom, 2);
			lst_f = lst_f->next;
		}
		else
		{
			maxnom = max_nom_lst(lst_f);
			while (lst_f && (lst_f->type != 99))
				i = ft_affichage_n2(w.ws_col, maxnom, &lst_f, i);
		}
	}
}

static void	affichage_ligne(int *max, t_liste **lst_f)
{
	ft_putchar((*lst_f)->type);
	ft_putstr((*lst_f)->droits);
	ft_putstr(" ");
	ft_putnbr_tab((*lst_f)->lien, max[0]);
	ft_putchar(' ');
	ft_putstr_tab((*lst_f)->nom_u, max[1]);
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putstr_tab((*lst_f)->groupe_u, max[2]);
	ft_putchar(' ');
	ft_putnbr_tab((*lst_f)->taille, max[3]);
	ft_putchar(' ');
	ft_putstr((*lst_f)->date_heure);
	ft_putchar(' ');
	ft_putstr((*lst_f)->nom);
	ft_putchar('\n');
	*lst_f = (*lst_f)->next;
}

void		ft_affichage_liste(t_liste *lst_f, int *option, int argc)
{
	int		*max;

	option[2] = 1;
	max = (int*)malloc(sizeof(int) * 5);
	if (argc < 3)
		lst_f = lst_f->next;
	while (lst_f)
	{
		if (lst_f->type == 99)
		{
			lst_f->type = ft_affichage_dossier(lst_f->nom, 1);
			lst_f = lst_f->next;
		}
		else
		{
			ft_bzero(max, 20);
			max = max_taille_lst(lst_f, max);
			ft_putstr("total ");
			ft_putnbr(max[4]);
			ft_putchar('\n');
			while (lst_f && lst_f->type != 99)
				affichage_ligne(max, &lst_f);
		}
	}
}
