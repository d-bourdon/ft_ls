/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajout_liste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:57:46 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/21 16:18:03 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_type(mode_t mode)
{
	mode = (mode & S_IFMT);
	if (mode & S_IFDIR)
		return ('d');
	else if (mode == 40960)
		return ('l');
	else
		return ('-');
}

char	*ft_lien_nom(char *nom, char *dir)
{
	char	*tmp;

	tmp = ft_strjoin(nom, " -> ");
	free(nom);
	nom = ft_strdup(ft_strjoin(tmp, dir));
	free(tmp);
	free(dir);
	return (nom);
}

void	ft_ajout_liste_dossier(t_liste **lst_f, char *arg)
{
	t_liste	*ajout;

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
	ft_strcpy(ajout->nom, arg);
	ajout->type = 99;
	ajout->next = NULL;
	ft_lstaddend(lst_f, ajout);
}

char	*lecture_lien(char *arg, char *nom)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 256);
	if (readlink(ft_path(arg, nom), tmp, 255))
		return (ft_lien_nom(nom, tmp));
	else
		return (nom);
}

t_liste	*ft_ajt_lst(struct dirent *lrd, struct stat *llst, int *opt, char *arg)
{
	t_liste		*ajout;

	ajout = (t_liste*)malloc(sizeof(t_liste));
	ajout->nom = ft_strdup(lrd->d_name);
	ajout->type = ft_dossier_fichier(ft_path(arg, lrd->d_name));
	ajout->next = NULL;
	if (opt[0] == 1 || opt[4] == 1)
	{
		ajout->type = ft_type(llst->st_mode);
		ajout->droits = ft_strdup(ft_chmod(llst->st_mode));
		ajout->lien = llst->st_nlink;
		ajout->groupe_u = ft_strdup(ft_cherche_g(llst->st_gid));
		ajout->nom_u = ft_strdup(ft_cherche_u(llst->st_uid));
		ajout->taille = (int)llst->st_size;
		ajout->nb_bloc = (int)llst->st_blocks;
		ajout->date_heure = ft_heure(llst->st_mtime);
		ajout->posix = llst->st_mtime;
		if (ajout->type == 'l')
			ajout->nom = lecture_lien(arg, ajout->nom);
	}
	return (ajout);
}
