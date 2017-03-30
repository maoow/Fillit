/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_available_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:05:44 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 21:38:35 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

bool	ft_check_available_tab(char *str)
{
	int		count;
	int		i;
	bool	last;

	last = false;
	count = 0;
	i = 0;
	while (*str && !last)
	{
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\0')
			return (false);
		if ((str[i] == '\n' && str[i + 1] == '\n') || str[i + 1] == '\0')
		{
			count++;
			if (str[i + 1] == '\0')
				last = true;
			str[i + 1] = '\0';
			if (!ft_check_available_tetri(str) || count > 26)
				return (false);
			str = &str[i + 2];
			i = 0;
		}
		i++;
	}
	return (true);
}
