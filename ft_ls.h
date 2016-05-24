/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:44:08 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/24 15:02:39 by dbourdon         ###   ########.fr       */
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
# include <pwd.h>
# include <time.h>
# include <sys/ioctl.h>
# include <stdint.h>

typedef struct		s_liste
{
	char			*nom;
	char			type;
	char			*droits;
	int				lien;
	char			*groupe_u;
	char			*nom_u;
	int				taille;
	int				nb_bloc;
	char			*date_heure;
	int				posix;
	struct s_liste	*next;
}					t_liste;

void				ft_erreur(char *str, int mode);
int					*ft_detection_option(char *str, int *option);
int					*ft_lecture_option(char ***argv, int *argc);
char				*ft_path(char *src, char *fichier);
void				ft_lstaddend(t_liste **liste, t_liste *ajout);
int					ft_ajout_liste_dossier(t_liste **lst_f, char *argument);
t_liste				*ft_ajt_lst(struct dirent *lrd, struct stat *llst,
						int *opt, char *arg);
void				ft_affichage_normal(t_liste *lst_f, int *option, int argc);
void				ft_affichage(t_liste *lst_f, int *option, int argc);
char				*ft_cherche_g(gid_t gid);
char				*ft_cherche_u(uid_t uid);
char				*ft_chmod(mode_t mode);
void				ft_lecture_liste(t_liste **lst_f, char *argument,
						int *option);
t_liste				*ft_pointe_fin_lst(t_liste **liste);
t_liste				*ft_trie_liste(t_liste *lst, int option);
t_liste				*ft_trie_liste_inv(t_liste *lst);
t_liste				*ft_trie_liste_temp(t_liste *lst, int option);
t_liste				*ft_trie_liste_temp_inv(t_liste *lst);
char				**ft_trie_tabtab(char **atrier, int taille);
char				ft_detection_type(uint8_t type);
char				ft_dossier_fichier(char *path);
char				*ft_heure(time_t heure);
int					max_nom_lst(t_liste *lst_f);
void				ft_affichage_liste(t_liste *lst_f, int *option, int argc);
int					*max_taille_lst(t_liste *lst, int *max);
void				ft_putnbr_tab(int nb, int max);
void				ft_putstr_tab(char *str, int max);
int					ft_lstswap_bac(t_liste **a);
int					ft_lstswap_acb(t_liste **a);
char				ft_type(mode_t mode);
char				*ft_lien_nom(char *nom, char *dir);
char				*lecture_lien(char *arg, char *nom);

#endif
