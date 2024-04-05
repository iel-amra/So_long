/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:50:26 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/10 16:40:21 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (dst[len] && len < (unsigned int) dstsize)
		len++;
	i = 0;
	while (src[i] && i + len + 1 < (unsigned int) dstsize)
	{
		dst[len + i] = src[i];
		i++;
	}
	if ((unsigned int) dstsize != len)
		dst[len + i] = '\0';
	while (src[i])
		i++;
	return (len + i);
}
