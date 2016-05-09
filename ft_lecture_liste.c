/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_liste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:45:52 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/09 14:05:32 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lecture_liste(t_liste *lst_f, char *argument, int *option)
{
	DIR				*fd;
	struct dirent	*lreaddir;
	struct stat		*llstat;
	t_liste			*tmplst = NULL;
	
	fd = opendir(argument);
	if (fd == NULL)
		return (ft_erreur(argument, 2));
	printf("On entre\n"); fflush(stdout);
	ft_ajout_liste_dossier(lst_f, argument);
	printf("On a ajoute le dossier base\n"); fflush(stdout);
	tmplst = ft_pointe_fin_lst(&(lst_f));
	printf("On lastpointe\n"); fflush(stdout);
	llstat = (struct stat*)malloc(sizeof(struct stat));
	while((lreaddir = readdir(fd)) != NULL)
	{
		printf("On boucle sur readdir\n"); fflush(stdout);
		if (option[0] == 1 || option[4] == 1)
			lstat(ft_path(argument, lreaddir->d_name), llstat);
		if (lreaddir->d_name[0] != '.' )
		ft_lstaddend(&(lst_f), ft_ajout_liste(lreaddir, llstat, option));
	}
	printf("Hop on sort de la boucle\n");fflush(stdout);
	if (option[4] == 1)
	{
		ft_trie_liste_temp(tmplst, option[4], &(ft_cmp));
		printf("On trie la liste qu nivequ du temps\n"); fflush(stdout);
	}
	else
	{
		ft_trie_liste(tmplst, option[4], &(ft_cmp));
		printf("On trie les entree par leur nom\n");fflush(stdout);
	}
		if(option[2] == 1)
	{
		while(tmplst->next != NULL)
		{
			if (tmplst->type == 1 && !(ft_strcmp(tmplst->nom, ".") || ft_strcmp(tmplst->nom, "..")))
				ft_lecture_liste(lst_f, ft_path(argument, tmplst->nom), option);
			tmplst = tmplst->next;
		}
	}
	printf("On a fini la lecture sur %s\n", argument);fflush(stdout);
}
