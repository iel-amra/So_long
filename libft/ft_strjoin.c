/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <iel-amra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:47:02 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 15:11:30 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return ((void *) 0);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s3 == (void *) 0)
		return ((void *) 0);
	while (*s1)
	{
		s3[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		s3[i] = *s2;
		s2++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
