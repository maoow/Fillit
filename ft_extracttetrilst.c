/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extracttetrilst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:21:03 by starrit           #+#    #+#             */
/*   Updated: 2016/12/01 19:02:56 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrilst	*ft_extracttetrilst(t_tetrilst *lst, int pos)
{
	t_tetrilst	*prev;
	t_tetrilst	*current;
	int			i;

	i = 0;
	if (pos == 0 || pos >= ft_bt_count(lst))
		return (lst);
	current = lst;
	while (i < pos)
	{
		prev = current;
		current = current->next;
		i++;
	}
	prev->next = current->next;
	current->next = lst;
	return (current);
}
