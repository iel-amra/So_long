/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:39:39 by iel-amra          #+#    #+#             */
/*   Updated: 2022/03/29 10:44:19 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	init_assets(t_assets *assets, void *mlx)
{
	assets->tab = reader(assets->path);
	if (!assets->tab || parsing(assets->tab, assets->path))
		return (1);
	assets->coder = get_coder();
	if (!assets->coder)
	{
		double_free(assets->tab);
		return (1);
	}
	if (init_tileset(assets->tileset, mlx))
	{
		double_free(assets->tab);
		double_free(assets->coder);
		return (1);
	}
	init_assets_var(assets, mlx);
	assets->background = new_image(mlx, assets->map.x, assets->map.y);
	if (get_background(&assets->background, mlx))
	{
		free_tileset(assets->tileset, mlx);
		double_free(assets->coder);
		double_free(assets->tab);
		return (1);
	}
	return (0);
}

void	init_assets_var(t_assets *assets, void *mlx)
{
	init_map(assets, mlx);
	init_hit_map(assets, mlx);
	assets->nb_coll = nb_char_in_tab(assets->tab, 'C') * MULTI_COLL;
	assets->nb_enemies = place_enemies(assets->tab);
	assets->nb_portals = nb_char_in_tab(assets->tab, 'E');
	assets->nb_objects = 1 + assets->nb_coll
		+ assets->nb_enemies + assets->nb_portals;
	assets->collected = 0;
	assets->nb_move = 0;
}
