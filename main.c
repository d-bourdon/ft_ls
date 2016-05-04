/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:45:27 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/04 15:38:13 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		*option;
	int		i;
	t_liste	*lst_f;
	DIR		fd;
	int		chmod;
	struct dirent	*test;
	struct stat		*kstat;

	argv++;
	i = 0;
	kstat = (struct stat*)malloc(sizeof(struct stat));
	argc = 1;
	option = ft_lecture_option(&(argv));
	while (argv[i])
		ft_lecture_liste(lst_f, argv[i++], option);
	printf("%d\n%d\n%d\n%d\n%d\n", option[0], option[1], option[2], option[3], option[4]);
	printf("%s", argv[0]);
	fd = *opendir(argv[0]);
	while ((test = readdir(&fd)) != NULL)
	{
		i = lstat(ft_path(argv[0], test->d_name), kstat);
		chmod = kstat->st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
		printf("%d | %lld | %hu | %d | %s\n",i ,kstat->st_size, kstat->st_mode, chmod, test->d_name);fflush(stdout);
	}
	return (0);
}
