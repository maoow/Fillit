/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_place_tetri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:30:09 by starrit           #+#    #+#             */
/*   Updated: 2016/11/27 13:34:47 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_bt_place_tetri(char **tab, t_tetrilst *tetri, t_point pos)
{
	int		i;
	int		j;
	int		t;
	int		count;

	i = pos.y;
	j = pos.x;
	t = 0;
	count = 0;
	while (i < (pos.y + 4))
	{
		while (count < 4)
		{
			if (tetri->tetri[t] != '.')
				tab[i][j] = tetri->tetri[t];
			j++;
			t++;
			count++;
		}
		count = 0;
		j = pos.x;
		i++;
		t++;
	}
	return (tab);
}
