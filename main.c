/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:45:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/05 11:48:25 by dbourdon         ###   ########.fr       */
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
	argc = 1;
	option = ft_lecture_option(&(argv), &(argc));
	liste_arg = ft_trie_tabtab(argv, argc);
	while (liste_arg[i])
		ft_lecture_liste(lst_f, argv[i++], option);
	chmod = kstat->st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
	return (0);
}
