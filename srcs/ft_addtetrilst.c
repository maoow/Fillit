/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtetrilst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:30:30 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/01 17:30:40 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrilst	*ft_addtetrilst(t_tetrilst *lst, char *str)
{
	t_tetrilst	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = ft_newtetrilst(str);
	return (lst);
}
