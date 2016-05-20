/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_liste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:45:52 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/20 12:45:14 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lecture_liste(t_liste **lst_f, char *argument, int *option)
{
	int				nb;
	DIR				*fd;
	struct dirent	*lreaddir;
	struct stat		*llstat;
	t_liste			*tmplst = NULL;
	
	nb = 0;
	fd = opendir(argument);
	if (fd == NULL)
		return (ft_erreur(argument, 2));
	ft_ajout_liste_dossier(lst_f, argument);
	tmplst = ft_pointe_fin_lst(lst_f);
	llstat = (struct stat*)malloc(sizeof(struct stat));
	while((lreaddir = readdir(fd)) != NULL)
	{
		nb++;
		if (option[0] == 1 || option[4] == 1)
			lstat(ft_path(argument, lreaddir->d_name), llstat);
		if (option[1] == 1 || lreaddir->d_name[0] != '.' )
		{
			ft_lstaddend(lst_f, ft_ajout_liste(lreaddir, llstat, option, argument));
		}
	}
	closedir(fd);
	if (option[4] == 1)
		ft_trie_liste_temp(tmplst, option[3]);
	else
		tmplst = ft_trie_liste(tmplst, option[3]);
	if(option[2] == 1)
	{
		while(tmplst && nb >= 0)
		{
			nb--;
			if (tmplst->type == 'd' && !(ft_strcmp(tmplst->nom, ".") == 0 || ft_strcmp(tmplst->nom, "..") == 0))
			{
				ft_lecture_liste(lst_f, ft_path(argument, tmplst->nom), option);
			}
			tmplst = tmplst->next;
		}
	}
}
