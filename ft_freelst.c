/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:57:27 by starrit           #+#    #+#             */
/*   Updated: 2016/12/02 17:22:09 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelst(t_tetrilst **lst)
{
	t_tetrilst	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->tetri);
		free(*lst);
		*lst = next;
	}
}
