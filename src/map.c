/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:24:07 by iel-amra          #+#    #+#             */
/*   Updated: 2022/03/29 10:42:08 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	add_map(t_assets *assets, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (assets->tab[y][x] != '1')
		return ;
	while (assets->coder[j]
		&& (assets->coder[j][i] != get_code(assets->tab, x, y)))
	{
		i = 0;
		while (assets->coder[j][i]
				&& assets->coder[j][i] != get_code(assets->tab, x, y))
			i++;
		if (assets->coder[j][i] != get_code(assets->tab, x, y))
			j++;
	}	
	put_tile(assets->tileset[i] + j, &assets->map, x * 128, y * 128);
}

void	init_map(t_assets *assets, void *mlx)
{
	int	i;
	int	j;

	assets->map = new_image(mlx,
			ft_strlen(assets->tab[0]) * 128, len_tab(assets->tab) * 128);
	paint_background(&assets->map, 0xFF000000);
	j = 0;
	while (assets->tab[j])
	{
		i = 0;
		while (assets->tab[j][i])
		{
			add_map(assets, i, j);
			i++;
		}
		j++;
	}
}

int	get_code(char	**tab, int x, int y)
{
	unsigned char	code;
	unsigned char	coins;
	int				i;
	int				j;

	code = 0;
	i = -1;
	j = -1;
	while (i != -1 || j != 0)
	{
		code = (code + code_pos(tab, x + i, y + j)) << 1;
		if ((j == -1 && i != 1) - (j == 1 && i != -1))
			i += (j == -1 && i != 1) - (j == 1 && i != -1);
		else
			j += (i == 1 && j != 1) - (i == -1 && j != -1);
	}
	code = code + code_pos(tab, x + i, y + j);
	coins = (code & ((code << 1) + (code >> 7))
			& ((code >> 1) + (code << 7))) & 0xAA;
	code = code & 0x55;
	if ((code | coins) == 0)
		return (2);
	return (code | coins);
}

unsigned char	code_pos(char	**tab, int x, int y)
{
	int	len_x;
	int	len_y;

	len_x = ft_strlen(*tab);
	len_y = 0;
	while (tab[len_y])
		len_y++;
	if (x < 0 || y < 0 || x >= len_x || y >= len_y)
		return (1);
	return (tab[y][x] == '1');
}
