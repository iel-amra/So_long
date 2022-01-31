/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:38:23 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/10 12:24:46 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*memory;

	memory = malloc(count * size);
	if (memory == (void *) 0)
		return ((void *) 0);
	i = 0;
	while (i < count * size)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
