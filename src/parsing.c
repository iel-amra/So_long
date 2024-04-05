/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:32:12 by iel-amra          #+#    #+#             */
/*   Updated: 2022/04/12 17:28:39 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	parse_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	return (1);
}

int	parsing(char **tab, char *path)
{
	if (!*tab)
		return (parse_error("Empty map"));
	if (!is_ber(path))
		return (parse_error("Not a .ber map"));
	if (!map_rectangle(tab))
		return (parse_error("Not rectangle map"));
	if (nb_char_in_tab(tab, 'C') == 0)
		return (parse_error("Put at least one collectible"));
	if (nb_char_in_tab(tab, 'E') == 0)
		return (parse_error("Put at least one enemy"));
	if (nb_char_in_tab(tab, 'P') == 0)
		return (parse_error("Put at least one starting point"));
	if (no_other(tab))
		return (parse_error("Character not recongnized in map"));
	if (!wall_surrounded(tab))
		return (parse_error("The map is not surrounded by walls"));
	return (0);
}

int	map_rectangle(char **tab)
{
	int	len;
	int	i;

	len = ft_strlen(*tab);
	i = 1;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	wall_surrounded(char **tab)
{
	int	i;
	int	len;
	int	length_tab;

	length_tab = len_tab(tab);
	len = ft_strlen(tab[0]);
	i = 0;
	while (tab[0][i])
	{
		if (tab[0][i] != '1')
			return (0);
		if (tab[length_tab - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] != '1')
			return (0);
		if (tab[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_ber(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	if (ft_strcmp(".ber", path + len - 4))
		return (0);
	return (1);
}
