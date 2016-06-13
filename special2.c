/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 15:34:20 by dbourdon          #+#    #+#             */
/*   Updated: 2016/06/13 11:39:15 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	renvoie_d(t_liste **lst_f, int *opt, struct dirent *lrd, char *arg)
{
	struct stat	*llstat;
	t_liste		*tmp;
	t_liste		*tmp2;
	DIR			*fd;

	fd = opendir(lrd->d_name);
	if (errno == EACCES || errno == ENOENT)
		return (ft_erreur(lrd->d_name, 2));
	llstat = (struct stat*)malloc(sizeof(struct stat));
	if (opt[0] == 1 || opt[4] == 1 || opt[5] == 1)
		lstat(lrd->d_name, llstat);
	if (opt[1] == 1 || lrd->d_name[0] != '.')
	{
		tmp2 = ft_ajt_lst(lrd, llstat, opt, arg);
		tmp = ft_pointe_avant_n(lst_f);
		if (tmp->next)
			tmp2->next = tmp->next;
		tmp->next = tmp2;
	}
}
