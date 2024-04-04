/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:59:52 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/05 19:05:36 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*new;

	if (!s1)
		return ((void *) 0);
	i = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && (ft_strchr(set, s1[i - 1])))
		i--;
	new = malloc((i + 1) * sizeof(char));
	if (!new)
		return ((void *) 0);
	new[i] = '\0';
	i--;
	while (i >= 0)
	{
		new[i] = s1[i];
		i--;
	}
	return (new);
}
