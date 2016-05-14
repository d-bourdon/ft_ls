/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajout_liste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:57:46 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/14 16:41:36 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_dossier_fichier(char *path)
{
	DIR		*fd;

	fd = opendir(path);
	if (fd != NULL)
	{
		closedir(fd);
		return ('d');
	}
	else
		return ('-');
}

void	ft_ajout_liste_dossier(t_liste **lst_f, char *argument, t_info f)
{
	t_liste		*ajout = NULL;

	printf("Welcom to ft_ajout_liste_dossier\n"); fflush(stdout);
	ajout = (t_liste*)malloc(sizeof(t_liste));
	ajout->nom = (char*)malloc(sizeof(char) * ft_strlen(argument));
	ajout->droits = NULL;
	ajout->lien = 0;
	ajout->groupe_u = NULL;
	ajout->taille = 0;
	ajout->date_heure = NULL;
	ajout->info = f;
	ft_strcpy(ajout->nom, argument);
	printf("On strcopy -> %s\n", ajout->nom); fflush(stdout);
	ajout->type = 99;
	ajout->next = NULL;
	printf("On set\n"); fflush(stdout);
	ft_lstaddend(lst_f, ajout);
	printf("On addend\n"); fflush(stdout);
}

t_liste	*ft_ajout_liste(struct dirent *lreaddir, struct stat *llstat, int *option, char *argument, t_info f)
{
	t_liste		*ajout;

	ajout = (t_liste*)malloc(sizeof(t_liste));
	ajout->nom = ft_strdup(lreaddir->d_name);
	ajout->type = ft_dossier_fichier(ft_path(argument, lreaddir->d_name));
	printf("Valeur de d_type : %u", lreaddir->d_type);
	ajout->next = NULL;
	ajout->info = f;
	f->maxnom = (ft_strlen(ajout->nom) > f->maxnom)? ft_strlen(ajout->nom) : f->maxnom ;
	if (option[0] == 1 || option[4] == 1)
	{
		ajout->droits = ft_strdup(ft_chmod(llstat->st_mode));
		ajout->lien = llstat->st_nlink;
		f->maxlien = (ft_intlen(ajout->lien) > f->maxlien)? ft_intlen(ajout->lien) : f->maxlien ;
		ajout->groupe_u = ft_strdup(ft_cherche_u(llstat->st_gid));
		f->maxg = (ft_strlen(ajout->groupe_u) > f->maxg)? ft_strlen(ajout->group_u) : f->maxg ;
	//f->maxu = (ft_strlen(ajout->utili_u) > f->maxg)? ft_strlen(ajout->group_u) : f->maxg ;
		ajout->taille = (int)llstat->st_size;
		f->maxtaille = (ft_intlen(ajout->taille) > f->maxtaille)? ft_intlen(ajout->taille) : f->maxtaille ;
		ajout->date_heure = ft_heure(llstat->st_mtime);
	}
	return (ajout);
}
