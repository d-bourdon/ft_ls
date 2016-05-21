/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:34:03 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/21 16:45:48 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_chmod(mode_t mode)
{
	char	*tmp;

	tmp = strdup("---------");
	if (mode & S_IRUSR)
		tmp[0] = 'r';
	if (mode & S_IWUSR)
		tmp[1] = 'w';
	if (mode & S_IXUSR)
		tmp[2] = 'x';
	if (mode & S_IRGRP)
		tmp[3] = 'r';
	if (mode & S_IWGRP)
		tmp[4] = 'w';
	if (mode & S_IXGRP)
		tmp[5] = 'x';
	if (mode & S_IROTH)
		tmp[6] = 'r';
	if (mode & S_IWOTH)
		tmp[7] = 'w';
	if (mode & S_IXOTH)
		tmp[8] = 'x';
	return (tmp);
}
