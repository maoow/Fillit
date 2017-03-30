/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:35:53 by starrit           #+#    #+#             */
/*   Updated: 2016/11/29 19:11:39 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_bt_count(t_tetrilst *lst)
{
	int count;

	count = 1;
	if (lst)
	{
		while (lst->next)
		{
			count++;
			lst = lst->next;
		}
		return (count);
	}
	else
		return (0);
}
