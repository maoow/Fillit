/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 02:18:06 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*str;
	int				i;

	if (!s1 || !s2)
		return (NULL);
	if ((str = (char *)malloc((ft_strlen((char *)s1) +
						ft_strlen((char *)s2) + 1) * sizeof(*str))) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
	{
		str[i] = s2[len];
		len++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
