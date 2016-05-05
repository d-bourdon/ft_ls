/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_tabtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 10:26:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/05 15:41:22 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_trie_tabtab(char **atrier, int	taille)
{
	char	**trier;
	char	*tmp;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	trier = (char	**)malloc(sizeof(char*) * taille);
	tmp = ft_strdup(argv[0]);
	while (i < taille)
	{
		while (i < taille)
		{
			if((ft_strcmp(tmp, atrier[i])) < 0)
			{
				free(tmp);
				tmp = strdup(atrier[i]);
				i = -1;
			}
			i++;
		}
		trier[j] = ft_strdup(tmp);
		j++;
	}
}
int	main(void)
{
	char **str;
	char **out;
	int i;

	i = 0;
	str = (char **)malloc(sizeof(char*) * 4);
	str[0] = ft_strdup("tien");
	str[1] = ft_strdup("prend");
	str[2] = ft_strdup("ca_dans");
	str[3] = ft_strdup("ta_gueule");
	out = ft_trie_tabtab(str);
	while (out[i] != NULL)
		printf("%s\n", out[i++]);fflush(stdout);
	return(0);
}
