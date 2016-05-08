/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_liste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:41:52 by exam              #+#    #+#             */
/*   Updated: 2016/05/08 14:12:08 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmp(int a, int b, int option)
{
	if (option == 1)
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
	t_liste	*tmpa, *tmpb, *tmpc;
	int		is_sorted;

	if (!lst)
		return (lst);
	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		while (lst && lst->next && !cmp((int)lst->nom, (int)lst->next->nom, option))
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
			if (tmpc && !cmp((int)tmpb->nom, (int)tmpc->nom, option))
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

t_liste *ft_trie_liste_temp(t_liste *lst, int option, int (*cmp)(int, int, int))
{
	t_liste	*tmpa, *tmpb, *tmpc;
	int		is_sorted;

	if (!lst)
		return (lst);
	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		while (lst && lst->next && !cmp((int)lst->date_heure, (int)lst->next->date_heure, option))
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
			if (tmpc && !cmp((int)tmpb->date_heure, (int)tmpc->date_heure, option))
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
