/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_liste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:41:52 by exam              #+#    #+#             */
/*   Updated: 2016/05/07 12:05:54 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmp(int a, int b, int option)
{
	if(option == 1)
	{
		if (a < b)
			return (-1);
		else
			return (1);
	}
	if (a > b)
		return (-1);
	else
		return (1);
}

t_liste *ft_trie_liste(t_liste *lst, int option, int (*cmp)(int, int, int))
{
	t_list	*tmpa, *tmpb, *tmpc;
	int		is_sorted;

	if (!lst)
		return (lst);
	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		while (lst && lst->next && !cmp(lst->data, lst->next->data, option))
		{
			tmpa = lst->next;
			lst->next = lst->next->next;
			tmpa->next = lst;
			lst = tmpa;
			is_sorted = 0;
		}
		tmpa = lst;
		while (tmpa && tmpa->next)
		{
			tmpb = tmpa->next;
			tmpc = tmpb->next;
			if (tmpc && !cmp(tmpb->data, tmpc->data))
			{
				is_sorted = 0;
				tmpa->next = tmpc;
				tmpb->next = tmpc->next;
				tmpc->next = tmpb;
			}
			else
				tmpa = tmpa->next;
		}
	}
	return (lst);
}
