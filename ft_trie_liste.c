/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_liste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 10:41:52 by exam              #+#    #+#             */
/*   Updated: 2016/05/19 15:21:51 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_liste	*ft_ajout_debut_lst(t_liste *lst)
{
	printf("On entre dans ajout debut\n");fflush(stdout);
	t_liste	*tmp;
	t_liste *tmp2;

	tmp = lst;
	while (tmp && tmp->next && tmp->next->type != 99)
	{
		tmp = tmp->next;
	}
	printf("On a trouve notre 99\n"); fflush(stdout);
	if (tmp && tmp->next && tmp->next->type == 99)
	{
		printf("ici ?"); fflush(stdout);
		tmp2 = tmp->next;
		printf("aie\n");fflush(stdout);
		if (tmp->next->next && tmp->next->next->next)
			tmp->next = tmp->next->next->next;
		else
			tmp->next = NULL;
		printf("a nop"); fflush(stdout);
		tmp2->next = lst;
		lst = tmp2;
	}
	printf("fini"); fflush(stdout);
	return (lst);
}

t_liste *ft_trie_liste_inv(t_liste *lst)
{
	t_liste	*tmpa, *tmpb, *tmpc;
	int		is_sorted;

	if (!lst)
		return (lst);
	is_sorted = 1;
	while (is_sorted)
	{
		is_sorted = 0;
		if (lst && lst->next && (ft_strcmp(lst->nom, lst->next->nom) < 0))
			is_sorted = ft_lstswap_bac(&lst);
		tmpa = lst;
		while (tmpa && tmpa->next && tmpa->next->next)
		{
			tmpb = tmpa->next;
			tmpc = tmpb->next;
			if (tmpc && (ft_strcmp(tmpb->nom, tmpc->nom) < 0))
				is_sorted = ft_lstswap_acb(&tmpa);
			else
				tmpa = tmpa->next;
		}
	}
	return (ft_ajout_debut_lst(lst));
}

t_liste *ft_trie_liste(t_liste *lst, int option)
{
	t_liste	*tmpa, *tmpb, *tmpc;
	int		is_sorted;

	if (!lst)
		return (lst);
	if (option == 1)
		return (ft_ajout_debut_lst(ft_trie_liste_inv(lst)));
	is_sorted = 1;
	while (is_sorted)
	{
		is_sorted = 0;
		if (lst && lst->next && (ft_strcmp(lst->nom, lst->next->nom) > 0))
			is_sorted = ft_lstswap_bac(&lst);
		tmpa = lst;
		while (tmpa && tmpa->next && tmpa->next->next)
		{
			tmpb = tmpa->next;
			tmpc = tmpb->next;
			if (tmpc && (ft_strcmp(tmpb->nom, tmpc->nom) > 0))
				is_sorted = ft_lstswap_acb(&tmpa);
			else
				tmpa = tmpa->next;
		}
	}
	return (ft_ajout_debut_lst(lst));
}

t_liste *ft_trie_liste_temp_inv(t_liste *lst)
{
	t_liste	*tmpa, *tmpb, *tmpc;
	int		is_sorted;

	if (!lst)
		return (lst);
	is_sorted = 1;
	while (is_sorted)
	{
		is_sorted = 0;
		while (lst && lst->next && (lst->posix < lst->next->posix))
			is_sorted = ft_lstswap_bac(&lst);
		tmpa = lst;
		while (tmpa && tmpa->next)
		{
			tmpb = tmpa->next;
			tmpc = tmpb->next;
			if (tmpc && (tmpb->posix < tmpc->posix))
				is_sorted = ft_lstswap_acb(&tmpa);
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

	if (!lst)
		return (lst);
	if (option == 0)
		return (ft_ajout_debut_lst(ft_trie_liste_temp_inv(lst)));
	is_sorted = 1;
	while (is_sorted)
	{
		is_sorted = 0;
		while (lst && lst->next && (lst->posix > lst->next->posix))
			is_sorted = ft_lstswap_bac(&lst);
		tmpa = lst;
		while (tmpa && tmpa->next)
		{
			tmpb = tmpa->next;
			tmpc = tmpb->next;
			if (tmpc && (tmpb->posix > tmpc->posix))
				is_sorted = ft_lstswap_acb(&tmpa);
			else
				tmpa = tmpa->next;
		}
	}
	return (lst);
}
