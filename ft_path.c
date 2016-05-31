/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:43:30 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/31 14:31:12 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_path(char *src, char *fichier)
{
	char	*tmp;
	int		taille;

	tmp = ft_strdup(src);
	taille = ft_strlen(src) - 1;
	if (!(src[taille] == '/'))
		tmp = ft_strjoinfree(tmp, "/", 1);
	tmp = ft_strjoinfree(tmp, fichier, 1);
	return (tmp);
}
