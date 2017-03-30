/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloctetritab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:26:43 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 17:27:43 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	***ft_cut_cpy(char ***tab, int i, int j)
{
	while (i < 104)
	{
		while (j < 104)
		{
			tab[0][i][j] = '.';
			tab[1][i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

char		***ft_malloctetritab(char ***tab)
{
	int i;
	int j;

	tab = (char ***)malloc(2 * sizeof(*tab));
	tab[0] = (char **)malloc(104 * sizeof(**tab));
	tab[1] = (char **)malloc(104 * sizeof(**tab));
	i = 0;
	while (i < 104)
	{
		tab[0][i] = (char *)malloc(sizeof(**tab) * 104);
		tab[1][i] = (char *)malloc(sizeof(**tab) * 104);
		i++;
	}
	i = 0;
	j = 0;
	return (ft_cut_cpy(tab, i, j));
}
