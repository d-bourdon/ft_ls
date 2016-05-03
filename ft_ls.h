/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:44:08 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/03 16:48:30 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct				s_simple_listing
{
	char					*nom;
	int						type;
	int						type_s;
	struct s_simple_listing	*nexit;
}							t_sliste;

typedef struct				s_compl_listing
{
	char					*nom;
	int						type;
	char					*droits;
	int						lien;
	char					*groupe_u;
	int						taille;
	char					*date_heure;
	int						type_s;
	struct s_compl_listing	*next;
}							t_cliste;

void						ft_erreur(char *str, int mode);
int							*ft_detection_option(char *str, int *option);
int							*ft_lecture_option(char ***argv);
char						*ft_path(char *src, char *fichier);

#endif
