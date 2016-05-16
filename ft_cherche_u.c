/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cherche_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:57:01 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/16 16:28:53 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_cherche_g(gid_t gid)
{
	struct group	*info;

	info = getgrgid(gid);
	return (info->gr_name);
}

char	*ft_cherche_u(uid_t uid)
{
	struct passwd *info;

	if((info = getpwuid(uid)) != NULL)
		return (info->pw_name);
	return(NULL);
}
