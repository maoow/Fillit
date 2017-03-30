/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:21:37 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 17:39:44 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

bool	ft_tetricmp(char *str, char *str2)
{
	while (*str && *str2)
	{
		if (*str == '.' && *str2 != '.')
			return (false);
		if (*str2 == '.' && *str != '.')
			return (false);
		str++;
		str2++;
	}
	return (true);
}

int		ft_getfirstextract(t_tetrilst *lst)
{
	int i;

	i = 0;
	while (lst->next && ft_tetricmp(lst->tetri, lst->next->tetri))
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		ft_getempty(char **tab, int size)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i][j] == '.')
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

bool	ft_checkifempty(char **tab, t_point pos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < pos.x)
	{
		while (j < pos.y)
		{
			if (tab[i][j] == '.')
				return (true);
			j++;
		}
		i++;
		j = 0;
	}
	return (false);
}
