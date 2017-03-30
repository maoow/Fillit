/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_getpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:50:54 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 18:04:33 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static bool			ft_bt_placeable(char **tab, t_tetrilst *lst, t_point pos)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lst->tetri[x + y * 5] != '.'
					&& tab[y + pos.y][x + pos.x] != '.')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static int			ft_getlastline(char **tab)
{
	bool	used;
	int		i;
	int		j;

	used = true;
	i = 0;
	j = 0;
	while (j < 104 && used == true)
	{
		used = false;
		while (i < 104)
		{
			if (tab[j][i] != '.')
				used = true;
			i++;
		}
		i = 0;
		j++;
	}
	return (j - 1);
}

static t_point		ft_bt_nextpos(char **tab, t_tetrilst *lst, int npos,
		t_point pos)
{
	int			size;

	size = ft_getlastline(tab);
	while (npos)
	{
		pos.x = 0;
		pos.y++;
		while (!ft_bt_placeable(tab, lst, pos))
		{
			if (pos.x == 103)
			{
				pos.verif = false;
				return (pos);
			}
			pos.x++;
		}
		npos--;
		if (pos.y > size)
		{
			pos.verif = false;
			return (pos);
		}
	}
	pos.verif = true;
	return (pos);
}

t_point				ft_bt_getpos(char **tab, t_tetrilst *lst, int npos)
{
	t_point		pos;

	pos.x = 0;
	pos.y = 0;
	while (!ft_bt_placeable(tab, lst, pos))
	{
		if (pos.x < 104)
			pos.x++;
		else
		{
			pos.x = 0;
			pos.y++;
		}
	}
	return (ft_bt_nextpos(tab, lst, npos, pos));
}
