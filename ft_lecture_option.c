/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:02:59 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/21 16:47:12 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ft_lecture_option(char ***argv, int *argc)
{
	int		i;
	int		*option;

	i = 0;
	option = (int*)malloc(sizeof(int) * 5);
	option = ft_bzero(option, 20);
	while ((*argv)[i] && (*argv)[i][0] == '-')
	{
		option = ft_detection_option((*argv)[i], option);
		i++;
	}
	*argv = *argv + (i);
	*argc = *argc - i;
	return (option);
}
