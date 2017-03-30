/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:50:35 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 18:00:24 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrilst	*ft_convert_thentetri(t_tetrilst *lst, char *str, int i, int count)
{
	str = &str[i + 2];
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != '\n' || str[i + 1] != '\n'))
		{
			if (str[i] == '#')
				str[i] = 'A' + count;
			i++;
		}
		if (str[i])
		{
			str[i] = '\0';
			ft_addtetrilst(lst, ft_align(ft_strdup(str)));
			str = &str[i + 2];
			i = 0;
		}
		else
			ft_addtetrilst(lst, ft_align(ft_strdup(str)));
		count++;
	}
	return (lst);
}

t_tetrilst	*ft_convert(char *str)
{
	int			i;
	t_tetrilst	*lst;
	int			count;

	count = 1;
	i = 0;
	while (str[i] && (str[i] != '\n' || str[i + 1] != '\n'))
	{
		if (str[i] == '#')
			str[i] = 'A';
		i++;
	}
	str[i] = '\0';
	lst = ft_newtetrilst(ft_align(ft_strdup(str)));
	if (str[i + 1] == '\n')
		lst = ft_convert_thentetri(lst, str, i, count);
	return (lst);
}
