/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_frames.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:10:03 by iel-amra          #+#    #+#             */
/*   Updated: 2022/03/23 13:55:27 by iel-amra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

t_data	*load_frames(char *path, int nb_frames, void *mlx)
{
	int		i;
	t_data	*frames;

	frames = malloc(sizeof(*frames) * nb_frames);
	if (!frames)
		return ((void *) 0);
	i = 0;
	while (i < nb_frames)
	{
		if (load_one_frame(frames + i, path, i, mlx))
		{
			free_frames(frames, i, mlx);
			return ((void *) 0);
		}
		i++;
	}
	return (frames);
}

int	load_one_frame(t_data *frame, char *path, int i, void *mlx)
{
	char	*temp;
	char	*temp2;

	if (i <= 9)
		path = ft_strjoin(path, "0000");
	else
		path = ft_strjoin(path, "000");
	temp = ft_itoa(i);
	if (!temp)
		return (1);
	temp2 = ft_strjoin(path, temp);
	free(temp);
	if (!temp2)
		return (1);
	free(path);
	path = ft_strjoin(temp2, ".xpm");
	free(temp2);
	if (!path)
		return (1);
	*frame = image_xpm(mlx, path);
	free(path);
	if (!frame->img)
		return (1);
	return (0);
}
