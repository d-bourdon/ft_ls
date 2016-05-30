/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_liste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:45:52 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/30 17:15:41 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		ft_dossier_fichier(char *path)
{
	DIR		*fd;

	if (readlink(path, "", 15))
		if (errno != EINVAL)
			return ('-');
	fd = opendir(path);
	if (fd != NULL)
	{
		closedir(fd);
		return ('d');
	}
	else
		return ('-');
}

static void	renvoie(t_liste **lst_f, int *opt, struct dirent *lrd, char *arg)
{
	struct stat	*llstat;

	llstat = (struct stat*)malloc(sizeof(struct stat));
	if (opt[0] == 1 || opt[4] == 1 || opt[5] == 1)
		lstat(ft_path(arg, lrd->d_name), llstat);
	if (opt[1] == 1 || lrd->d_name[0] != '.')
		ft_lstaddend(lst_f, ft_ajt_lst(lrd, llstat, opt, arg));
}

void		ft_lecture_liste(t_liste **lst_f, char *argument, int *option)
{
	DIR				*fd;
	struct dirent	*lreaddir;
	t_liste			*tmplst;

	fd = opendir(argument);
	if (fd == NULL)
		return (ft_erreur(argument, 2));
	ft_ajout_liste_dossier(lst_f, argument);
	tmplst = ft_pointe_fin_lst(lst_f);
	while ((lreaddir = readdir(fd)) != NULL)
		renvoie(lst_f, option, lreaddir, argument);
	closedir(fd);
	if (option[4] == 1)
		ft_trie_liste_temp(tmplst, option[3]);
	else
		tmplst = ft_trie_liste(tmplst, option[3]);
	if (option[2] == 1)
		tmplst = tmplst->next;
	while (tmplst && tmplst->type != 9)
	{
		if (tmplst->type == 'd' && !(ft_strcmp(tmplst->nom, ".") == 0
				|| ft_strcmp(tmplst->nom, "..") == 0))
			ft_lecture_liste(lst_f, ft_path(argument, tmplst->nom), option);
		tmplst = tmplst->next;
	}
}
