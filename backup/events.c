void	close_prog(t_vars *vars)
{
	vars->closing = 1;
	while (vars->rendering);
	free_assets(vars->mlx, &vars->assets);
	free_objects(vars->objects, vars->mlx);
	mlx_destroy_image(vars->mlx, vars->world[0].img);
	mlx_destroy_image(vars->mlx, vars->world[1].img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_do_key_autorepeaton(vars->mlx);
	exit(0);
}

int	key_down(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->keys[0] = 1;
	if (keycode == 0)
	{
		vars->keys[1] = 1;
		vars->keys[3] = 0;
	}
	if (keycode == 1)
		vars->keys[2] = 1;
	if (keycode == 2)
	{
		vars->keys[3] = 1;
		vars->keys[1] = 0;
	}
	if (keycode == 48)
		vars->keys[4] = 1 - vars->keys[4];
	if (keycode == 9)
		vars->keys[5] = 1 - vars->keys[5];
	if (keycode == 53)
		close_prog(vars);
	return (0);
}

int	key_up(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->keys[0] = 0;
	if (keycode == 0)
		vars->keys[1] = 0;
	if (keycode == 1)
		vars->keys[2] = 0;
	if (keycode == 2)
		vars->keys[3] = 0;
	return (0);
}
