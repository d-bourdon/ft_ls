/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajout_liste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:57:46 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/04 17:07:35 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ajout_liste_dossier(t_liste *lst_f, char *argument)
{
	t_liste		*ajout;

	ajout = (struct *s_liste)malloc(sizeof(s_liste));
	ajout->nom = (char*)malloc(sizeof(char) * ft_strlen(argument));
	ft_strcpy(ajout->nom, argument);
	ajout->type = 99;
	ajout->next = NULL;
	ft_lstaddend(*lst_f, ajout);
}

t_liste	*ft_ajout_liste(struct dirent lreaddir, struct stat llstat, int *option)
{
	t_liste		ajout;

	ajout = (struct *s_liste)malloc(sizeof(s_liste));
	ajout->nom = ft_strdup(lreaddir->d_name);
	ajout->type = (int)lreaddir->d_type;
	if (option[0] == 1 || option[4] == 1)
	{
		ajout->droits = ft_strdup(ft_chmod(llstat->st_mode));
		ajout->lien = llstat->st_nlink;
		ajout->groupe_u = ft_cherche_u(llstat->st_gid);
		ajout->taille = (int)llstat->st_size;
		ajout->date_heure = ft_heure_unix(llstats->st_mtime);
	}
	return (ajout);
}
