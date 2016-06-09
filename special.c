/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:34:20 by dbourdon          #+#    #+#             */
/*   Updated: 2016/06/08 16:25:57 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ajout_liste_dossier_d(t_liste **lst, char *arg)
{
	t_liste		ajout;
	t_liste		*tmp;

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

t_liste	*ft_pointe_avant_n(t_liste **lst)
{
	t_liste		*tmp;

	tmp = *lst;
	while (tmp && tmp->next && tmp->next->type != 9)
		tmp = tmp->next;
	return (tmp);
}

void	renvoie_d(t_liste **lst_f, int *opt, struct dirent *lrd, char *arg)
{
	struct stat	*llstat;
	t_liste		*tmp;
	t_liste		*tmp2;

	llstat = (struct stat*)malloc(sizeof(struct stat));
	if (opt[0] == 1 || opt[4] == 1 || opt[5] == 1)
		lstat(ft_path(arg, lrd->d_name), llstat);
	if (opt[1] == 1 || lrd->d_name[0] != '.')
	{
		tmp2 = ft_ajt_lst(lrd, llstat, opt, arg);
		tmp = ft_pointe_avant_n(lst);
		if (tmp->next)
			tmp2->next = tmp->next;
		tmp->next = tmp2;
	}
}

struct dirent *def_lreaddir(char *arg)
{
	struct dirent	lrd;
	
	lrd = (struct dirent)malloc(sizeof(struct dirent) * 1);
	lrd.d_name = ft_strdup(arg);
	lrd.d_type = NULL;

	return (&lrd);
}