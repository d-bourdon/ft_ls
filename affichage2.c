/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 14:16:37 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/26 14:39:54 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			max_nom_lst(t_liste *lst_f)
{
	t_liste	*tmp;
	int		i;
	int		taille;

	taille = 0;
	i = 0;
	tmp = lst_f;
	while (tmp && (tmp->type != 9))
	{
		i = ft_strlen(tmp->nom);
		if (i > taille)
			taille = i;
		tmp = tmp->next;
	}
	return (taille + 3);
}

void		ft_affichage(t_liste *lst_f, int *option, int argc)
{
	if (lst_f == NULL)
		ft_erreur("", 3);
	if (option[0] != 1)
		ft_affichage_normal(lst_f, option, argc);
	else
		ft_affichage_liste(lst_f, option, argc);
}
