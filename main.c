/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:45:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/16 16:10:44 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		*option;
	int		i;
	t_liste	*lst_f = NULL;
	char	**liste_arg;

	argv++;
	i = 0;
	printf("On start\n"); fflush(stdout);
	option = ft_lecture_option(&(argv), &(argc));
	printf("On as lu\n"); fflush(stdout);
	liste_arg = ft_trie_tabtab(argv, argc);
	if (argc == 1)
		argc++;
	printf("On as trier\n"); fflush(stdout);
	while (i < (argc - 1) && liste_arg[i] != NULL)
	{
		printf("On boucle %s\n", liste_arg[i]); fflush(stdout);
		ft_lecture_liste(&lst_f, liste_arg[i++], option);
	}
	printf("\n\nOn as fini de boucler\n"); fflush(stdout);
	ft_affichage(lst_f, option, argc);
	printf("Hehe on a fini !\n");fflush(stdout);
	return (0);
}
