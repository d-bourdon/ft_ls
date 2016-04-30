/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 13:45:15 by dbourdon          #+#    #+#             */
/*   Updated: 2016/04/30 14:55:47 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_erreur(char *str, int mode)
{
	if (mode == 1)
	{
		ft_putstr("ls: option invalide --");
		ft_putchar(str[0]);
		ft_putstr("\n utilisation: ls [-laRrt] [fichier ...]");
		exit(0);
	}
}
