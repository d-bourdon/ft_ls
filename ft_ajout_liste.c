/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajout_liste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:57:46 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/19 17:28:48 by dbourdon         ###   ########.fr       */
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
	ajout->posix = 0;
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
	char		*tmp;

	ajout = (t_liste*)malloc(sizeof(t_liste));
	ajout->nom = ft_strdup(lreaddir->d_name);
	ajout->type = ft_dossier_fichier(ft_path(argument, lreaddir->d_name));
	printf("Valeur de d_type : %u", lreaddir->d_type);
	ajout->next = NULL;
	if (option[0] == 1 || option[4] == 1)
	{
		ajout->type = ft_type(llstat->st_mode);
		ajout->droits = ft_strdup(ft_chmod(llstat->st_mode));
		ajout->lien = llstat->st_nlink;
		ajout->groupe_u = ft_strdup(ft_cherche_g(llstat->st_gid));
		ajout->nom_u = ft_strdup(ft_cherche_u(llstat->st_uid));
		ajout->taille = (int)llstat->st_size;
		ajout->nb_bloc = (int)llstat->st_blocks;
		ajout->date_heure = ft_heure(llstat->st_mtime);
		ajout->posix = llstat->st_mtime;
		if (ajout->type == 'l')
		{
			tmp = (char*)malloc(sizeof(char)*256);
			if (readlink(ft_path(argument, ajout->nom), tmp, 255))
				ajout->nom = ft_lien_nom(ajout->nom, tmp);
		}
	}
	return (ajout);
}
