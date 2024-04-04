/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+   :*/
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:13:26 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/10 16:43:37 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *) haystack);
	while (haystack[i] && needle[j] && i < (unsigned int) len)
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j]
			&& i + j < (unsigned int) len)
			j++;
		if (needle[j])
			i++;
	}
	if (haystack[i] == '\0' || i == (unsigned int) len)
		return ((void *) 0);
	return ((char *) haystack + i);
}
