/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:51:25 by starrit           #+#    #+#             */
/*   Updated: 2016/12/02 20:35:32 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define X(value) value % 5
# define Y(value) value / 5

typedef struct	s_tetrilst
{
	char				*tetri;
	struct s_tetrilst	*next;
}				t_tetrilst;

typedef	struct	s_point
{
	int					x;
	int					y;
	bool				verif;
}				t_point;

typedef	struct	s_tabsize
{
	int					min;
	int					actual;
	bool				exactmin;
}				t_tabsize;
char			*ft_align(char *str);
t_tetrilst		*ft_newtetrilst(char *str);
t_tetrilst		*ft_addtetrilst(t_tetrilst *lst, char *str);
t_tetrilst		*ft_extracttetrilst(t_tetrilst *start, int pos);
void			ft_deltetrilst(t_list *alltetri);
void			ft_delonetetrilst(t_list *tetri);
bool			ft_check_available_tetri(char *str);
bool			ft_check_available_tab(char *str);
int				ft_sqrt(int nb);
int				ft_bt_count(t_tetrilst *lst);
int				ft_bt_getsize_tab(char **tab, t_tabsize size);
t_tetrilst		*ft_convert(char *str);
char			**ft_bt_place_tetri(char **tab, t_tetrilst *tetri, t_point pos);
char			**ft_bt_remove_tetri(char **tab,
		t_tetrilst *tetri, t_point pos);
t_point			ft_bt_getpos(char **tab, t_tetrilst *lst, int npos);
char			*ft_read(char *str);
char			***ft_malloctetritab(char ***tab);
t_tabsize		ft_tetribacktrack(t_tetrilst *lst, t_point pos,
		char ***tab, t_tabsize size);
char			***ft_setdefinitive(char ***tab);
void			ft_disptetritab(char **tab, int size);
void			ft_freelst(t_tetrilst **lst);
t_tetrilst		*ft_intracttetrilst(t_tetrilst *lst, int pos);
bool			ft_tetricmp(char *str, char *str2);
int				ft_getfirstextract(t_tetrilst *lst);
int				ft_getempty(char **tab, int size);
bool			ft_checkifempty(char **tab, t_point pos);
#endif
