/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disptetritab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:51:17 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/01 19:02:22 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_disptetritab(char **tab, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			ft_putchar(tab[j][i]);
			i++;
		}
		j++;
		i = 0;
		ft_putendl("");
	}
}
