/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:44:08 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/08 14:14:37 by dbourdon         ###   ########.fr       */
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
	struct s_liste			*next;
}							t_liste;

void						ft_erreur(char *str, int mode);
int							*ft_detection_option(char *str, int *option);
int							*ft_lecture_option(char ***argv, int *argc);
char						*ft_path(char *src, char *fichier);
void						ft_lstaddend(t_liste **liste, t_liste *ajout);
void						ft_ajout_liste_dossier(t_liste *lst_f, char *argument);
t_liste						*ft_ajout_liste(struct dirent lreaddir, struct stat llstat, int *option);
void						ft_affichage_normal(t_liste *lst_f, int *option, int argc);
void						ft_affichage(t_liste *lst_f, int *option, int argc);
char						*ft_recherche_u(gid_t gid);
char						*ft_chmod(mode_t mode);
void						ft_lecture_liste(t_liste *lst_f, char *argument, int *option);
t_liste						ft_pointe_fin_lst(t_liste *liste);
int							ft_cmp(int a, int b, int option);
t_liste						*ft_trie_liste(t_liste *lst, int option, int (*cmp)(int, int, int));
t_liste						*ft_trie_liste_temp(t_liste *lst, int option, int (*cmp)(int, int, int));
char						**ft_trie_tabtab(char **atrier, int taille);



#endif
