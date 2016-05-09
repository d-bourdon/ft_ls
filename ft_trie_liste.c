/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_liste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:41:52 by exam              #+#    #+#             */
/*   Updated: 2016/05/09 18:31:21 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_liste *ft_trie_liste(t_liste *lst, int option)
{
	t_liste	*tmpa, *tmpb, *tmpc;
	int		is_sorted;

	if (!lst || option == 99)
		return (lst);
	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		if (lst && lst->next && (ft_strcmp(lst->nom, lst->next->nom) > 0))
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
			if (tmpc && (ft_strcmp(tmpb->nom, tmpc->nom) > 0))
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

t_liste *ft_trie_liste_temp(t_liste *lst, int option)
{
	t_liste	*tmpa, *tmpb, *tmpc;
	int		is_sorted;

	if (!lst || option == 99)
		return (lst);
	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		while (lst && lst->next && !ft_strcmp(lst->date_heure, lst->next->date_heure))
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
			if (tmpc && !ft_strcmp(tmpb->date_heure, tmpc->date_heure))
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
