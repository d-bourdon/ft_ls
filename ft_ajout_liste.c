/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajout_liste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:57:46 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/17 16:07:35 by dbourdon         ###   ########.fr       */
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

void	ft_ajout_liste_dossier(t_liste **lst_f, char *argument)
{
	t_liste		*ajout = NULL;

	printf("Welcom to ft_ajout_liste_dossier\n"); fflush(stdout);
	ajout = (t_liste*)malloc(sizeof(t_liste));
	ajout->nom = (char*)malloc(sizeof(char) * ft_strlen(argument));
	ajout->droits = NULL;
	ajout->lien = 0;
	ajout->groupe_u = NULL;
	ajout->nom_u = NULL;
	ajout->taille = 0;
	ajout->nb_bloc = 0;
	ajout->date_heure = NULL;
	ft_strcpy(ajout->nom, argument);
	printf("On strcopy -> %s\n", ajout->nom); fflush(stdout);
	ajout->type = 99;
	ajout->next = NULL;
	printf("On set\n"); fflush(stdout);
	ft_lstaddend(lst_f, ajout);
	printf("On addend\n"); fflush(stdout);
}

t_liste	*ft_ajout_liste(struct dirent *lreaddir, struct stat *llstat, int *option, char *argument)
{
	t_liste		*ajout;

	ajout = (t_liste*)malloc(sizeof(t_liste));
	ajout->nom = ft_strdup(lreaddir->d_name);
	ajout->type = ft_dossier_fichier(ft_path(argument, lreaddir->d_name));
	printf("Valeur de d_type : %u", lreaddir->d_type);
	ajout->next = NULL;
	if (option[0] == 1 || option[4] == 1)
	{
		ajout->droits = ft_strdup(ft_chmod(llstat->st_mode));
		ajout->lien = llstat->st_nlink;
		ajout->groupe_u = ft_strdup(ft_cherche_g(llstat->st_gid));
		ajout->nom_u = ft_strdup(ft_cherche_u(llstat->st_uid));
		ajout->taille = (int)llstat->st_size;
		ajout->nb_bloc = (int)llstat->st_blocks;
		ajout->date_heure = ft_heure(llstat->st_mtime);
	}
	return (ajout);
}
