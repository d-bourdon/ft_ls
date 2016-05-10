/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:01:22 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/10 13:59:47 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_ls.h"
 
 void	ft_lstaddend(t_liste **liste, t_liste *ajout)
 {
 	t_liste	*tmp;
 
 	tmp = *liste;
	printf("ajout -> %s\n", ajout->nom);fflush(stdout);
 	if (*liste == NULL)
	{
 		*liste = ajout;
		return ;
	}
 	else
 	{
		printf("On cherche la fin origine ->%s\n", (*liste)->nom);fflush(stdout);
 		while (tmp && tmp->next)
		{
 			tmp = tmp->next;
		}
		printf("we find end\n");fflush(stdout);
		if (ajout != NULL)
 			tmp->next = ajout;
	}
}
