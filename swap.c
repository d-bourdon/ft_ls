/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:31:22 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/19 14:28:09 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lstswap_bac(t_liste **a)
{
	t_liste	*b;

	if (!(*a) || !((*a)->next) || !((*a)->next->next))
		return (0);
	b = (*a)->next;
	(*a)->next = (*a)->next->next;
	b->next = *a;
	*a = b;
	return (1);
}

int		ft_lstswap_acb(t_liste **a)
{
	t_liste	*b;
	t_liste	*c;

	if (!(*a) || !((*a)->next) || !((*a)->next->next))
		return (0);
	b = (*a)->next;
	c = b->next;
	(*a)->next = c;
	b->next = c->next;
	c->next = b;
	return (1);
}
