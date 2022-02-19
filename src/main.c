

void	edit_next_frame(t_vars *vars, t_data *new)
{
	update_objects(vars->objects, &vars->assets.hit_map, vars->keys, &vars->assets);	
	check_end(vars);
	display_objects(vars->objects, new, vars->keys, vars->assets.nb_objects);
	restore_map(new, vars->objects, &vars->assets.map, vars->assets.nb_objects);
	if (vars->keys[4] && !vars->dis_hit[vars->nloaded])
	{
		put_tile(&vars->assets.hit_map, new, 0, 0);
		vars->dis_hit[vars->nloaded] = 1;
	}
	else if (!vars->keys[4] && vars->dis_hit[vars->nloaded])
	{
		paint_background(new, 0x00505050 );
		put_tile(&vars->assets.map, new, 0, 0);
		vars->dis_hit[vars->nloaded] = 0;
	}
}

int	render_next_frame(t_vars *vars)
{
	//t_time past = current_time();
	int	x;
	int	y;

	if (vars->closing)
		return (0);
	vars->rendering = 1;
	//edit_next_frame(vars, (vars->img) + (vars->nloaded));
	edit_next_frame(vars, (vars->world) + (vars->nloaded));
	cadre_frame(&x, &y, vars->objects, vars->world);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->world[vars->nloaded].img, x, y);
	vars->nloaded = 1 - vars->nloaded;
	clean_world(vars->world + vars->nloaded, vars->objects, &vars->assets);
	vars->rendering = 0;
	//time_disp(time_diff(current_time(), past));
	usleep(6000);	
	return (0);	
}

int	init_vars(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < NB_KEYS)
	{
		vars->keys[i] = 0;
		i++;
	}
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "So_long");
	if (init_assets(&vars->assets, vars->mlx))
			return (1);
	if (init_objects(&vars->assets, &vars->objects, vars->mlx))
	{
		free_assets(vars->mlx, &vars->assets);
		return (1);
	}
	init_world(vars);
	cadre_frame(&x, &y, vars->objects, vars->world);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->world[0].img, x, y);
	vars->nloaded = 1;
	vars->closing = 0;
	return (0);
}

void	init_world(t_vars *vars)
{
	vars->world[0] = new_image(vars->mlx, vars->assets.map.x, vars->assets.map.y);
	vars->world[1] = new_image(vars->mlx, vars->assets.map.x, vars->assets.map.y);
	put_tile(&vars->assets.background, vars->world, 0, 0);
	put_tile(&vars->assets.background, vars->world + 1, 0, 0);
	//paint_background(vars->world, 0x00505050 );
	//paint_background(vars->world + 1, 0x00505050 );
	display_objects(vars->objects, vars->world, vars->keys, vars->assets.nb_objects);
	display_objects(vars->objects, vars->world + 1, vars->keys, vars->assets.nb_objects);
	put_tile(&vars->assets.map, vars->world, 0, 0);	
	put_tile(&vars->assets.map, vars->world + 1, 0, 0);
	vars->dis_hit[0] = 0;
	vars->dis_hit[1] = 0;
}

int	main(int argc, char**argv)
{
	(void) argc;
	t_vars	vars;

	vars.assets.path = argv[1];
	if (init_vars(&vars))
		return (0);
	mlx_do_key_autorepeatoff(vars.mlx);
	mlx_hook(vars.win, 2, 1L<<0, key_down, &vars);
	mlx_hook(vars.win, 3, 1L<<1, key_up, &vars);
	mlx_hook(vars.win, 25, 1L<<18, close_prog, &vars);
	mlx_hook(vars.win, 17, 1L<<17, close_prog, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
