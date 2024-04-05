/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:09:08 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/05 16:45:15 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	new_len;

	i = 0;
	new_len = 0;
	while (s[i] && new_len < (unsigned int) len)
	{
		if (i >= start)
			new_len++;
		i++;
	}
	return (new_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	new_len;

	if (!s)
		return ((void *) 0);
	new_len = get_length(s, start, len);
	new = malloc((new_len + 1) * sizeof(char));
	if (!new)
		return ((void *) 0);
	ft_strlcpy(new, s + start, new_len + 1);
	return (new);
}
