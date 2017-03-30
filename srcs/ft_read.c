/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:36:40 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/02 21:04:19 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(char *str)
{
	char	buf[11];
	int		fd;
	int		i;
	char	*strret;
	int		size;

	size = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((i = read(fd, buf, 10)))
		size += i;
	if ((strret = (char*)malloc((size + 1) * sizeof(*strret))) == NULL)
		return (NULL);
	close(fd);
	fd = open(str, O_RDONLY);
	i = 0;
	while ((size = read(fd, strret + i, 10)))
	{
		i += size;
	}
	strret[i] = '\0';
	close(fd);
	return (strret);
}
