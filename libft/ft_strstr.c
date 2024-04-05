/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+   :*/
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:13:26 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 18:13:51 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *) haystack);
	while (haystack[i] && needle[j])
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j])
			j++;
		if (needle[j])
			i++;
	}
	if (haystack[i] == '\0')
		return ((void *) 0);
	return ((char *) haystack + i);
}
