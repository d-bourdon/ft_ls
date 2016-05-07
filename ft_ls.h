/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:44:08 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/07 15:29:32 by dbourdon         ###   ########.fr       */
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
# include <grp.h>
# include <time.h>

typedef struct				s_liste
{
	char					*nom;
	int						type;
	char					*droits;
	int						lien;
	char					*groupe_u;
	int						taille;
	char					*date_heure;
	struct s_compl_listing	*next;
}							t_liste;

void						ft_erreur(char *str, int mode);
int							*ft_detection_option(char *str, int *option);
int							*ft_lecture_option(char ***argv, int *argc);
char						*ft_path(char *src, char *fichier);
void						ft_lstaddend(t_liste **liste, t_liste *ajout);
void						ft_ajout_liste_dossier(t_liste *lst_f, char *argument);
t_liste						*ft_ajout_liste(struct dirent lreaddir, struct stat llstat, int *option);

#endif
