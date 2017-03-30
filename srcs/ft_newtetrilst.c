/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtetrilst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:24:41 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/01 19:03:42 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrilst	*ft_newtetrilst(char *str)
{
	t_tetrilst	*new;

	if ((new = (t_tetrilst *)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->tetri = ft_strdup(str);
	new->next = NULL;
	return (new);
}
