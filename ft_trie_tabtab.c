/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_tabtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:26:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/09 14:35:49 by dbourdon         ###   ########.fr       */
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
		printf("	on est in"); fflush(stdout);
		trier = (char**)malloc(sizeof(char*) * 1);
		trier[0] = ft_strdup(".");
		return (trier);
	}
	printf("On start trie taille =%d\n", taille); fflush(stdout);
	trier = (char**)malloc(sizeof(char*) * (taille + 1));
	while (atrier[++i])
	{
		trier[i] = ft_strdup(atrier[i]);
		printf("copie de atrier dans trier i =%d et trier[i] = %s\n", i, trier[i]);fflush(stdout);
	}
	printf("on sort de la copie\n");fflush(stdout);
	i = 0;
	while (j == 0 )
	{
		printf("tant que j==0\n"); fflush(stdout);
		j = 1;
		while (i < (taille - 2))
		{
			printf("while trier i++ -> %d - %s\n", i, trier[i + 1]); fflush(stdout);
			if (ft_strcmp(trier[i], trier[i + 1]) > 0)
			{
				printf("start switch -");fflush(stdout);
				tmp = ft_strdup(trier[i]);
				free(trier[i]);
				trier[i] = ft_strdup(trier[i + 1]);
				free(trier[i + 1]);
				trier[i + 1] = ft_strdup(tmp);
				free(tmp);
				j = 0;
				printf("fin switch\n");fflush(stdout);
			}
			i++;
		}
		i = 0;
	}
	return (trier);
}
