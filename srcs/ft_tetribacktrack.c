/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetribacktrack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:13:19 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 17:39:07 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetrilst	*ft_cplst(t_tetrilst *lst)
{
	t_tetrilst	*new;

	if (!lst)
		return (NULL);
	new = ft_newtetrilst(lst->tetri);
	lst = lst->next;
	while (lst)
	{
		ft_addtetrilst(new, lst->tetri);
		lst = lst->next;
	}
	return (new);
}

static t_tetrilst	**ft_bt_pulllst(t_tetrilst **lst)
{
	t_tetrilst	*tmp;

	tmp = (*lst)->next;
	free((*lst)->tetri);
	free(*lst);
	*lst = tmp;
	return (lst);
}

static t_tabsize	ft_bt_check(t_tetrilst **tmp, t_point pos,
		char ***tab, t_tabsize size)
{
	if (pos.verif)
	{
		tab[0] = ft_bt_place_tetri(tab[0], *tmp, pos);
		tmp = ft_bt_pulllst(tmp);
	}
	if (ft_bt_getsize_tab(tab[0], size) >= size.actual ||
			size.actual == size.min || (size.actual < 104 &&
				ft_getempty(tab[0], size.actual - 1) < ft_bt_count(*tmp) * 4)
			|| (size.exactmin && size.actual == size.min + 1
				&& ft_checkifempty(tab[0], pos)))
		return (size);
	if (*tmp == NULL)
	{
		if (ft_bt_getsize_tab(tab[0], size) < size.actual)
		{
			tab = ft_setdefinitive(tab);
			size.actual = ft_bt_getsize_tab(tab[0], size);
		}
		return (size);
	}
	size.actual = 0;
	return (size);
}

static t_tabsize	ft_bt_place(t_tetrilst *tmp, char ***tab, t_tabsize size)
{
	int		j;
	t_point tmppos;

	j = 0;
	while ((ft_bt_getpos(tab[0], tmp, j)).verif && size.actual > size.min
			&& j < size.actual)
	{
		tmppos = ft_bt_getpos(tab[0], tmp, j);
		if (tmppos.y <= size.actual && tmppos.x <= size.actual)
		{
			size = ft_tetribacktrack(tmp, tmppos, tab, size);
			tab[0] = ft_bt_remove_tetri(tab[0], tmp, tmppos);
		}
		j++;
	}
	return (size);
}

t_tabsize			ft_tetribacktrack(t_tetrilst *lst, t_point pos,
		char ***tab, t_tabsize size)
{
	int			i;
	t_tetrilst	*tmp;
	int			firstextract;

	tmp = ft_cplst(lst);
	if ((i = ft_bt_check(&tmp, pos, tab, size).actual) != 0)
	{
		size.actual = i;
		ft_freelst(&tmp);
		return (size);
	}
	i = ft_bt_count(tmp);
	firstextract = ft_getfirstextract(tmp);
	while (i > firstextract && size.actual > size.min)
	{
		tmp = ft_extracttetrilst(tmp, i);
		size = ft_bt_place(tmp, tab, size);
		tmp = ft_intracttetrilst(tmp, i);
		i--;
	}
	ft_freelst(&tmp);
	return (size);
}
