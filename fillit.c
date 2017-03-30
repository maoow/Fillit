/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:54:18 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 21:47:28 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_dispusage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
}

static void	ft_launchbt(char *str)
{
	t_tetrilst	*lst;
	char		***tab;
	t_point		pos;
	t_tabsize	size;

	pos.verif = false;
	lst = ft_convert(str);
	tab = NULL;
	tab = ft_malloctetritab(tab);
	size.min = ft_sqrt(4 * ft_bt_count(lst));
	size.exactmin = false;
	if (4 * ft_bt_count(lst) == size.min * size.min)
		size.exactmin = true;
	size.actual = 104;
	size = ft_tetribacktrack(lst, pos, tab, size);
	ft_disptetritab(tab[1], size.actual);
	ft_freelst(&lst);
}

int			main(int ac, char **av)
{
	char		*str;
	char		*str2;

	if (ac != 2)
		ft_dispusage();
	else
	{
		str = ft_read(av[1]);
		if (!str || !*str)
			ft_putstr("error\n");
		else
		{
			str2 = ft_strdup(str);
			if (!ft_check_available_tab(str2))
				ft_putstr("error\n");
			else
				ft_launchbt(str);
			free(str2);
		}
		free(str);
	}
	return (0);
}
