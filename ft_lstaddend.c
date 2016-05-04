/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:01:22 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/04 11:06:30 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_ls.h"
 
 void	ft_lstaddend(t_liste **liste, t_liste *ajout)
 {
 	t_liste	*tmp;
 
 	tmp = *liste;
 	while (tmp->next != NULL)
 		tmp = tmp->next;
 	tmp->next = ajout;
 }
