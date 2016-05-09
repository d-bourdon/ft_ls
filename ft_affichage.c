/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:40:32 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/09 14:09:25 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_affichage_normal(t_liste *lst_f, int *option, int argc)
{
	int		i;

	if (option[0] == (argc + 100))
	{
		printf("On exit pour use argc\n"); fflush(stdout);
		exit(0);
	}
	i = 0;
//	printf("la liste = %s\n", lst_f->nom);fflush(stdout);
	while (lst_f && lst_f->next != NULL)
	{
		printf("Une  nouvelle ligne\n");fflush(stdout);
		while(i < 2 && lst_f && lst_f->next != NULL)
		{
			ft_putstr(lst_f->nom);
			ft_putstr("    ");
			i++;
			lst_f = lst_f->next;
		}
		printf("\nnext");fflush(stdout);
		ft_putchar('\n');
		i = 0;
	}
}

void	ft_affichage(t_liste *lst_f, int *option, int argc)
{
	if (lst_f == NULL)
		exit(0);
	if (option[0] != 1)
	{
		printf("test%s", lst_f->nom);fflush(stdout);
		ft_affichage_normal(lst_f, option, argc);
		printf("On affiche normalememt\n");fflush(stdout);
	}
		else
	{
		while (lst_f && lst_f->next != NULL)
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
