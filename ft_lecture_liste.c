/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_liste.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:45:52 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/13 15:08:37 by dbourdon         ###   ########.fr       */
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
	printf("On entre\n"); fflush(stdout);
	ft_ajout_liste_dossier(lst_f, argument);
	printf("On a ajoute le dossier base\n"); fflush(stdout);
	tmplst = ft_pointe_fin_lst(lst_f);
	printf("On lastpointe\n"); fflush(stdout);
	llstat = (struct stat*)malloc(sizeof(struct stat));
	while((lreaddir = readdir(fd)) != NULL)
	{
		nb++;
		printf("On boucle sur readdir\n"); fflush(stdout);
		if (option[0] == 1 || option[4] == 1)
			lstat(ft_path(argument, lreaddir->d_name), llstat);
		if (option[1] == 1 || lreaddir->d_name[0] != '.' )
		{
			ft_lstaddend(lst_f, ft_ajout_liste(lreaddir, llstat, option, argument));
			printf("On viens de add %s\n", lreaddir->d_name);fflush(stdout);
		}
	}
	closedir(fd);
	printf("Hop on sort de la boucle\n");fflush(stdout);
	if (option[4] == 1)
	{
		ft_trie_liste_temp(tmplst, option[4]);
		printf("On trie la liste qu nivequ du temps\n"); fflush(stdout);
	}
	else
	{
		tmplst = ft_trie_liste(tmplst, option[4]);
		printf("On trie les entree par leur nom\n");fflush(stdout);
	}
	if(option[2] == 1)
	{
		printf("Hey om recurcive");
		while(tmplst && nb > 0)
		{
			printf("Why not");
			nb--;
			if (tmplst->type == 'd' && !(ft_strcmp(tmplst->nom, ".") == 0 || ft_strcmp(tmplst->nom, "..") == 0))
			{

				ft_lecture_liste(lst_f, ft_path(argument, tmplst->nom), option);
				printf("Tout de meme !");
			}
			tmplst = tmplst->next;
			printf("\n\n		NEXT ---- > %s", argument); fflush(stdout);
		}
	}
	printf("On a fini la lecture sur %s\n", argument);fflush(stdout);
}
