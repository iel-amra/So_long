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
	exit(0);
	return (0);
}

int	key_down(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	if (keycode == 119 || keycode == 65362)
		vars->keys[0]++;
	if (keycode == 97 || keycode == 65361)
	{
		vars->keys[1]++;
		vars->keys[3] = 0;
	}
	if (keycode == 115 || keycode == 65364)
		vars->keys[2]++;
	if (keycode == 100 || keycode == 65363)
	{
		vars->keys[3]++;
		vars->keys[1] = 0;
	}
	if (keycode == 48)
		vars->keys[4] = 1 - vars->keys[4];
	if (keycode == 118)
		vars->keys[5] = 1 - vars->keys[5];
	if (keycode == 65307)
		close_prog(vars);
	return (0);
}

int	key_up(int keycode, t_vars *vars)
{
	if (keycode == 119 || keycode == 65362)
		vars->keys[0]--;
	if (keycode == 97 || keycode == 65361)
	{	
		if (vars->keys[1] > 0)
			vars->keys[1]--;
	}
	if (keycode == 115 || keycode == 65364)
		vars->keys[2]--;
	if (keycode == 100 || keycode == 65363)
	{	
		if (vars->keys[3] > 0)
			vars->keys[3]--;
	}
	return (0);
}
