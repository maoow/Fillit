/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_available_tetri.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:27:07 by starrit           #+#    #+#             */
/*   Updated: 2016/12/02 17:38:53 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static bool		ft_check_4x4(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i % 5 == 4 && str[i] != '\n' && str[i])
			return (false);
		if (i % 5 != 4 && (str[i] == '\n' || !str[i]))
			return (false);
		i++;
	}
	if (i == 20)
		return (true);
	return (false);
}

static bool		ft_check_char(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
			count++;
		else if (str[i] != '.' && str[i] != '\n' && str[i] != '\0')
			return (false);
		i++;
	}
	if (count == 4)
		return (true);
	return (false);
}

static bool		ft_double_touch(char *str, int i)
{
	int		count;

	count = 0;
	if (i - 1 >= 0 && str[i - 1] == '#')
		count++;
	if (i + 1 <= 19 && str[i + 1] == '#')
		count++;
	if (i - 5 >= 0 && str[i - 5] == '#')
		count++;
	if (i + 5 <= 19 && str[i + 5] == '#')
		count++;
	if (count > 1)
		return (true);
	return (false);
}

static bool		ft_touch(char *str, int i, int count)
{
	bool	touchone;
	bool	touchtwo;

	touchtwo = false;
	while (str[i] && count < 4)
	{
		if (str[i] == '#')
		{
			touchone = false;
			if ((i - 1 >= 0 && str[i - 1] == '#') || (i - 1 <= 19
					&& str[i + 1] == '#') || (i - 5 >= 0 && str[i - 5] == '#')
					|| (i + 5 <= 19 && str[i + 5] == '#'))
				touchone = true;
			if (touchone == false)
				return (false);
			count++;
			if (ft_double_touch(str, i))
				touchtwo = true;
		}
		i++;
	}
	if (touchtwo)
		return (true);
	return (false);
}

bool			ft_check_available_tetri(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!ft_check_4x4(str))
		return (false);
	if (!ft_check_char(str))
		return (false);
	if (!ft_touch(str, i, count))
		return (false);
	return (true);
}
