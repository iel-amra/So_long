/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:20:46 by iel-amra          #+#    #+#             */
/*   Updated: 2022/02/25 11:20:51 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	free_objects(t_object *objects, void *mlx)
{
	int	i;

	i = 0;
	while (objects[i].animes)
	{
		free_object(objects + i, mlx);
		i++;
	}
}

void	free_object(t_object *object, void *mlx)
{
	free_animes(object->animes, object->nb_animes, mlx);
	if (object->move)
		free(object->move);
	if (object->hit.img)
		mlx_destroy_image(mlx, object->hit.img);
}

void	free_animes(t_anime *animes, int nb, void *mlx)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free_frames(animes[i].frames, animes[i].total_frame, mlx);
		i++;
	}
	free(animes);
}

void	free_frames(t_data *frames, int nb, void *mlx)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		mlx_destroy_image(mlx, frames[i].img);
		i++;
	}
	free(frames);
}
