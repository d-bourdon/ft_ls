/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:02:59 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/02 10:40:15 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ft_lecture_option(char ***argv)
{
	int		i;
	int		*option;

	i = 0;
	option = (int*)malloc(sizeof(int) * 5);
	option = ft_bzero(option, 20);
	while ((*argv)[i]  && (*argv)[i][0] == '-')
	{
	//	printf("%s\n", (*argv)[i]);
		option = ft_detection_option((*argv)[i], option);
		i++;
	}
	*argv = *argv + (i);
	return (option);
}
