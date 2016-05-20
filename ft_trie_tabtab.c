/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_tabtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:26:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/20 10:21:31 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_trie_tabtab(char **atrier, int	taille)
{
	char	**trier;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (taille == 1)
	{
		trier = (char**)malloc(sizeof(char*) * 1);
		trier[0] = ft_strdup(".");
		return (trier);
	}
	trier = (char**)malloc(sizeof(char*) * (taille + 1));
	while (atrier[++i])
		trier[i] = ft_strdup(atrier[i]);
	i = 0;
	while (j == 0 )
	{
		j = 1;
		while (i < (taille - 2))
		{
			if (ft_strcmp(trier[i], trier[i + 1]) > 0)
			{
				tmp = ft_strdup(trier[i]);
				free(trier[i]);
				trier[i] = ft_strdup(trier[i + 1]);
				free(trier[i + 1]);
				trier[i + 1] = ft_strdup(tmp);
				free(tmp);
				j = 0;
			}
			i++;
		}
		i = 0;
	}
	return (trier);
}
