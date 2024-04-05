/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:22:19 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/10 15:44:50 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	if (!dst && !src)
		return ((void *) 0);
	i = 0;
	while (i < (int) n)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}
