/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:34:20 by dbourdon          #+#    #+#             */
/*   Updated: 2016/06/09 16:27:57 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ajout_liste_dossier_d(t_liste **lst, char *arg)
{
	t_liste		*ajout;

	ajout = (t_liste*)malloc(sizeof(t_liste));
	ajout->nom = (char*)malloc(sizeof(char) * ft_strlen(arg));
	ajout->droits = NULL;
	ajout->lien = 0;
	ajout->groupe_u = NULL;
	ajout->nom_u = NULL;
	ajout->taille = 0;
	ajout->nb_bloc = 0;
	ajout->posix = 0;
	ajout->date_heure = NULL;
	ft_strcpy(ajout->nom, ft_strjoin(arg, "\0"));
	ajout->type = 9;
	ajout->next = *lst;
	ajout->major = 0;
	ajout->minor = 0;
	*lst = ajout;
}

t_liste			*ft_pointe_avant_n(t_liste **lst)
{
	t_liste		*tmp;

	tmp = *lst;
	while (tmp && tmp->next && tmp->next->type != 9)
		tmp = tmp->next;
	return (tmp);
}

struct dirent	*def_lreaddir(char *arg)
{
	struct dirent	*lrd;

	lrd = (struct dirent*)malloc(sizeof(struct dirent) * 1);
	ft_strcpy(lrd->d_name, arg);
	return (lrd);
}
