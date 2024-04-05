/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:59:41 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/06 10:01:57 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!src && !dst)
		return ((void *) 0);
	i = 0;
	while (i < (int) len)
	{
		if (dst <= src)
			((char *) dst)[i] = ((char *) src)[i];
		else
			((char *) dst)[len - i - 1] = ((char *) src)[len - i - 1];
		i++;
	}
	return (dst);
}
