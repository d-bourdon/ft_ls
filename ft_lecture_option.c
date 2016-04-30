/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:02:59 by dbourdon          #+#    #+#             */
/*   Updated: 2016/04/30 14:56:06 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ft_lecture_option(char ***argv)
{
	int		i;
	int		*option;

	i = 0;
	option = (int*)malloc(sizeof(int) * 5);
	while (*argv[i] != NULL && *argv[i][0] == '-')
	{
		option = ft_detection_option(*argv[i], option);
		i++;
	}
	*argv = *argv + i;
	return (option);
}
