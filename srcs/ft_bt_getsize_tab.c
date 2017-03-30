/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_getsize_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:42:11 by starrit           #+#    #+#             */
/*   Updated: 2016/12/02 18:23:06 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_bt_getsize_tab(char **tab, t_tabsize size)
{
	int		j;
	bool	empty;

	size.actual = size.min;
	empty = false;
	while (!empty)
	{
		empty = true;
		j = 0;
		while (j <= size.actual)
		{
			if (tab[size.actual][j] != '.' || tab[j][size.actual] != '.')
				empty = false;
			j++;
		}
		size.actual++;
	}
	return (size.actual - 1);
}
