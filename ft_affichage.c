/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:40:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/12 14:42:45 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_affichage_normal(t_liste *lst_f, int *option, int argc)
{
	int		i;
	int		j;
	int		maxnom;
	t_liste	*tmp;
	struct winsize	w;

	tmp = lst_f;
	maxnom = 0;
	ioctl(0, TIOCGWINSZ, &w);
	while (tmp->next)
	{
		if ((int)ft_strlen(tmp->nom) > maxnom)
			maxnom = (int)ft_strlen(tmp->nom);
		tmp = tmp->next;
	}
	maxnom = maxnom + 3;
	if (option[0] == 100)
	{
		printf("On exit pour use argc\n"); fflush(stdout);
		exit(0);
	}
	i = 0;
	j = 0;
//	printf("la liste = %s\n", lst_f->nom);fflush(stdout);
	while (lst_f && lst_f->next != NULL)
	{
		//printf("Une  nouvelle ligne\n");fflush(stdout);
		while (i < (w.ws_col / maxnom) && lst_f)
		{
			if (lst_f->type == 99 && argc > 1)
			{
				ft_putstr("\n");
				ft_putstr(lst_f->nom);
				ft_putstr(":\n");
			}
			else
			{
				ft_putstr(lst_f->nom);
				while (j++ < (int)(maxnom - strlen(lst_f->nom)))
					ft_putstr(" ");
				i++;
				j = 0;
			}
			lst_f = lst_f->next;
		}
	//	printf("\nnext");fflush(stdout);
		ft_putchar('\n');
		i = 0;
	}
}

void	ft_affichage(t_liste *lst_f, int *option, int argc)
{
	int		maxtaille;

	maxtaille = 0;
	printf("on entre dans affichage\n"); fflush(stdout);
	if (lst_f == NULL)
	{
		printf("On exit car null\n");fflush(stdout);
		exit(0);
	}
	if (option[0] != 1)
	{
		ft_affichage_normal(lst_f, option, argc);
		printf("On affiche normalememt\n");fflush(stdout);
	}
		else
	{

		while (lst_f)
		{
			ft_putchar(lst_f->type);
			ft_putstr(lst_f->droits);
			ft_putstr("  ");
			ft_putnbr(lst_f->lien);
			ft_putchar(' ');
			ft_putstr(lst_f->groupe_u);
			ft_putchar(' ');
			ft_putnbr(lst_f->taille);
			ft_putchar(' ');
			ft_putstr(lst_f->date_heure);
			ft_putchar(' ');
			ft_putstr(lst_f->nom);
			ft_putchar('\n');
			lst_f = lst_f->next;
		}
	}
}
