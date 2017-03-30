/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:36:54 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 18:14:56 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static bool	ft_checky(char *str)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (str[i] != '.')
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_checkx(char *str)
{
	int		i;

	i = 0;
	while (Y(i) < 4)
	{
		if (str[i] != '.')
			return (false);
		i += 5;
	}
	return (true);
}

static char	*ft_cut_align(char *str, char *new, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 19)
	{
		new[i] = '.';
		if (X(i) == 4)
			new[i] = '\n';
		i++;
	}
	new[19] = '\0';
	i = 0;
	while (Y(y) + Y(j) < 4)
	{
		while (x + i < 4)
		{
			new[i + j] = str[i + j + y + x];
			i++;
		}
		i = 0;
		j += 5;
	}
	return (new);
}

char		*ft_align(char *str)
{
	int		x;
	int		y;
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	while (ft_checky(&str[y]))
		y += 5;
	while (ft_checkx(&str[x]))
		x++;
	if ((new = (char *)malloc(20 * sizeof(*new))) == NULL)
		return (NULL);
	new = ft_cut_align(str, new, x, y);
	return (new);
}
