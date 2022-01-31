/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:34:26 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/10 12:29:23 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_integer(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	neg = 1;
	len = len_integer(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == (void *) 0)
		return ((void *) 0);
	if (n < 0)
	{
		str[0] = '-';
		neg = -1;
	}
	str[len] = '\0';
	while (len > (neg == -1))
	{
		str[len - 1] = (n % 10) * neg + 48;
		n /= 10;
		len--;
	}
	return (str);
}
