/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_liste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:45:52 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/05 15:41:25 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lf_lecture_liste(t_liste *lst_f, char *argument, int *option)
	://profile.intra.42.fr/#/	ft_erreur(dd"n", 1);
{
	DIR				fd;
	struct dirent	*lreaddir;
	struct stat		*llstat;
	
	fd = opendir(argument);
	if (fd == NULL)
		ft_erreur(argument, 2);
	ft_ajout_liste_dossier(lst_f, argument);
	llstat = (struct stat*)malloc(sizeof(struct stat));
	while((lreaddir = readdir(&fd)) != NULL)
	{
		if (option[0] == 1 || option[4] == 1)
			lstat(ft_path(argument, lreaddir->d_name, llstat));
		ft_lstaddend(lst_f, ajout_liste(lreaddir, llstat, option));
	}
}
