int	close_prog(t_vars *vars)
{
	vars->closing = 1;
	while (vars->rendering);
	free_assets(vars->mlx, &vars->assets);
	free_objects(vars->objects, vars->mlx);
	mlx_destroy_image(vars->mlx, vars->world[0].img);
	mlx_destroy_image(vars->mlx, vars->world[1].img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_do_key_autorepeaton(vars->mlx);
	return (0);
}

int	key_down(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->keys[0] = 1;
	if (keycode == 97)
	{
		vars->keys[1] = 1;
		vars->keys[3] = 0;
	}
	if (keycode == 115)
		vars->keys[2] = 1;
	if (keycode == 100)
	{
		vars->keys[3] = 1;
		vars->keys[1] = 0;
	}
	if (keycode == 65289)
		vars->keys[4] = 1 - vars->keys[4];
	if (keycode == 118)
		vars->keys[5] = 1 - vars->keys[5];
	if (keycode == 65307)
		close_prog(vars);
	return (0);
}

int	key_up(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->keys[0] = 0;
	if (keycode == 97)
		vars->keys[1] = 0;
	if (keycode == 115)
		vars->keys[2] = 0;
	if (keycode == 100)
		vars->keys[3] = 0;
	return (0);
}
