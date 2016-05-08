/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointe_fin_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 11:29:12 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/08 14:15:15 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_liste	ft_pointe_fin_lst(t_liste *liste)
{
	t_liste		*tmp;

	tmp = liste;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return(tmp);
}
