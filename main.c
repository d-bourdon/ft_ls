/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:45:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/24 15:01:00 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		*option;
	int		i;
	t_liste	*lst_f;
	char	**liste_arg;

	argv++;
	i = 0;
	lst_f = NULL;
	option = ft_lecture_option(&(argv), &(argc));
	liste_arg = ft_trie_tabtab(argv, argc);
	if (argc == 1)
		argc++;
	while (i < (argc - 1) && liste_arg[i] != NULL)
		ft_lecture_liste(&lst_f, liste_arg[i++], option);
	ft_affichage(lst_f, option, argc);
	if (option[0] != 1)
		ft_putchar('\n');
	return (0);
}
