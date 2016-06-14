/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:43:30 by dbourdon          #+#    #+#             */
/*   Updated: 2016/06/14 14:55:09 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_path(char *src, char *fichier)
{
	char	*tmp;
	int		taille;

	tmp = src;
	taille = ft_strlen(src) - 1;
	if (!(src[taille] == '/'))
		tmp = ft_strjoin(tmp, "/");
	tmp = ft_strjoin(tmp, fichier);
	tmp = ft_strjoin(tmp, "\0");
	return (tmp);
}
