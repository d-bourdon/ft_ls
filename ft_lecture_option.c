/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:02:59 by dbourdon          #+#    #+#             */
/*   Updated: 2016/04/29 17:51:33 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ft_lecture_option(char **argv, **fichiersalire)
{
	int		i;
	int		*option;

	i = 0;
	option = (char*)malloc(sizeof(int) * 5);
	while (argv[i] != NULL && argv[i][0] == '-')
	{
		option = ft_detection_option(argv[i], option);
		i++;
	}
}
