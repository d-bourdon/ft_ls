/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_liste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:45:52 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/07 14:00:36 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lf_lecture_liste(t_liste *lst_f, char *argument, int *option)
{
	DIR				fd;
	struct dirent	*lreaddir;
	struct stat		*llstat;
	t_liste			*tmplst;
	
	fd = opendir(argument);
	if (fd == NULL)
		ft_erreur(argument, 2);
	ft_ajout_liste_dossier(lst_f, argument);
	tmplst = ft_pointe_fin_lst(lst_f);
	llstat = (struct stat*)malloc(sizeof(struct stat));
	while((lreaddir = readdir(&fd)) != NULL)
	{
		if (option[0] == 1 || option[4] == 1)
			lstat(ft_path(argument, lreaddir->d_name, llstat));
		ft_lstaddend(lst_f, ajout_liste(lreaddir, llstat, option));
	}
	if (option[4] == 1)
		ft_trie_liste_temp(tmplst, option[4], &(ft_cmp));
	else
		ft_trie_liste(tmplst, option[4], &(ft_cmp));
	if(option[2] == 1)
	{
		while(tmplst->next != NULL)
		{
			if (tmplst->type = 1 && (tmplst->name != "." || tmplst->name != ".."))
				ft_lecture_liste(lst_f, ft_path(argument, tmplst->name), option);
			tmplst = tmplst->next;
		}
	}
}
