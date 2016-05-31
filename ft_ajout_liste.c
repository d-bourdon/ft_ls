/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajout_liste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:57:46 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/31 14:36:28 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_type(mode_t mode)
{
	mode = (mode & S_IFMT);
	if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISSOCK(mode))
		return ('s');
	else
		return ('-');
}

char	*ft_lien_nom(char *nom, char *dir)
{
	char	*tmp;

	tmp = ft_strjoinfree(nom, " -> ", 1);
	nom = ft_strdup(ft_strjoinfree(tmp, ft_strjoinfree(dir, "\0", 1), 0));
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
	ft_strcpy(ajout->nom, ft_strjoin(arg, "\0"));
	ajout->type = 9;
	ajout->next = NULL;
	ajout->major = 0;
	ajout->minor = 0;
	ft_lstaddend(lst_f, ajout);
}

char	*lecture_lien(char *arg, char *nom)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * 256);
	if (readlink(ft_path(arg, nom), tmp, 255))
		return (ft_lien_nom(nom, tmp));
	else
		free(tmp);
		return (nom);
}

t_liste	*ft_ajt_lst(struct dirent *lrd, struct stat *llst, int *opt, char *arg)
{
	t_liste		*ajout;

	ajout = (t_liste*)malloc(sizeof(t_liste));
	ajout->nom = ft_strdup(ft_strjoin(lrd->d_name, "\0"));
	ajout->type = ft_dossier_fichier(ft_path(arg, lrd->d_name));
	ajout->next = NULL;
	if (opt[0] == 1 || opt[4] == 1 || opt[5] == 1)
	{
		ajout->major = major(llst->st_rdev);
		ajout->minor = minor(llst->st_rdev);
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
