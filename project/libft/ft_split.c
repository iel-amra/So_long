/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:52:19 by iel-amra          #+#    #+#             */
/*   Updated: 2021/11/10 15:21:16 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_mots(char const *s, char *charset)
{
	int	nb_m;

	nb_m = 0;
	while (*s)
	{
		while (*s && ft_strchr(charset, *s))
			s++;
		if (*s)
			nb_m++;
		while (*s && !ft_strchr(charset, *s))
			s++;
	}
	return (nb_m);
}

static int	*nb_lettres(char const *s, char *charset, int nb_m)
{
	int	i;
	int	*nb_l;

	i = 0;
	nb_l = malloc((nb_m) * sizeof(int));
	if (nb_l == (void *) 0)
		return ((void *) 0);
	while (i < nb_m)
	{
		nb_l[i] = 0;
		while (ft_strchr(charset, *s))
			s++;
		while (*s && !ft_strchr(charset, *s))
		{
			nb_l[i]++;
			s++;
		}
		i++;
	}
	return (nb_l);
}

static void	fill_tab(char const *s, char *charset, char **tab, int nb_m)
{
	int		i;
	int		j;

	if (!tab)
		return ;
	i = 0;
	while (i < nb_m)
	{
		while (ft_strchr(charset, *s))
			s++;
		j = 0;
		while (*s && !ft_strchr(charset, *s))
		{
			tab[i][j] = *s;
			s++;
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = (void *) 0;
}

static void	free_begin_tab(char ***tab, int fin)
{
	int	i;

	i = 0;
	while (i < fin)
		free((*tab)[i++]);
	free(*tab);
	*tab = (void *) 0;
}

char	**ft_split(char const *s, char *charset)
{
	int		i;
	int		*nb_l;
	int		nb_m;
	char	**tab;

	if (!s)
		return ((void *) 0);
	i = 0;
	nb_m = nb_mots(s, charset);
	nb_l = nb_lettres(s, charset, nb_m);
	tab = malloc((nb_m + 1) * sizeof(char *));
	if (tab == (void *) 0 || nb_l == (void *) 0)
		return ((void *) 0);
	while (i < nb_m && tab)
	{
		tab[i] = malloc((nb_l[i] + 1) * sizeof(char));
		if (tab[i] == (void *) 0)
			free_begin_tab(&tab, i);
		i++;
	}
	free(nb_l);
	fill_tab(s, charset, tab, nb_m);
	return (tab);
}
