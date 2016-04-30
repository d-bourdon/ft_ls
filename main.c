/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:45:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/04/30 16:53:46 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		*option;

	argv++;
	if (argc == 1)
		ft_erreur("n", 1);
	option = ft_lecture_option(&(argv));
	printf("%d\n%d\n%d\n%d\n%d\n", option[0], option[1], option[2], option[3], option[4]);
	printf("%s", argv[0]);

	return (0);
}
