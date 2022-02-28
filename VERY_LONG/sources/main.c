#include "../Headers/so_long.h"

void	ft_free(void *tofree)
{
	if (tofree)
		free(tofree);
	tofree = NULL;
}

int	ft_free_dchar(char **str)
{ 
	int i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	if (str)
	{	
		free(str);
		str = NULL;
	}
	return (1);
}

int	ft_check_error(int argc, char **argv, t_data *data) //verif map existe
{
	if (argc == 0)
		return (error_code(data, 1));
	if (directory_check(*argv))
		return (error_code(data, 2));
	if (map_ber(*argv))
		return (error_code(data, 3));
	if (count_line_col(&data->map, argv[0]))
		return (error_code(data, 4));
	if (fill_map(data, *argv))
		return (error_code(data, 5));
	if (check_walls_around(data))
		return (error_code(data, 6));
	if (check_letters(data))
		return (error_code(data, 7));
	return (0);	
}

void	render_wall(t_data *data, int i, int j)
{
	if (i == 0 && (j > 0 && j < (data->map.x - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->texture.wall_up.img, \
		j * TILE_SIZE, i * TILE_SIZE);
	else if (j == 0 && (i > 0 && i < (data->map.y - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->texture.wall_left.img, \
		j * TILE_SIZE, i * TILE_SIZE);
	else if (j == (data->map.x - 1)
		&& (i > 0 && i < (data->map.y - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->texture.wall_right.img, \
		j * TILE_SIZE, i * TILE_SIZE);
	else if (i == (data->map.y - 1) && j == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->texture.corner_d_l.img, \
		j * TILE_SIZE, i * TILE_SIZE);
	else if (i == 0 && j == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->texture.corner_u_l.img, \
		j * TILE_SIZE, i * TILE_SIZE);
	else if (i == 0 && j == (data->map.x - 1))
		mlx_put_image_to_window(data->mlx, data->win, data->texture.corner_u_r.img, \
		j * TILE_SIZE, i * TILE_SIZE);
	else if (i == (data->map.y - 1) && j == (data->map.x - 1))
		mlx_put_image_to_window(data->mlx, data->win, data->texture.corner_d_r.img, \
		j * TILE_SIZE, i * TILE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->texture.wall_down.img, \
		j * TILE_SIZE, i * TILE_SIZE);
}

int	count_collectible(t_data data)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (data.map.map[i][j])
	{
		while (data.map.map[i])
		{
			if (data.map.map[i][j] == 'C')
				c++;
			i++;
		}
		i = 0;
		j++;
	}	
	return (c);
}

void	display_map(t_data data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data.map.map[i][j])
	{
		while (data.map.map[i])
			parsing_display(&data, i++, j);
		i = 0;
		j++;
	}	
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		endgame(data);
		exit(0);
	}
	if (keycode == 119)
		move_player(data, 'w');
	if (keycode == 100)
		move_player(data, 'd');
	if (keycode == 97)
		move_player(data, 'a');
	if (keycode == 115)
		move_player(data, 's');
	return (0);
}

void	destroy_mlx_imgs(t_data *data)
{
	if (data->texture.augustin.img)
		mlx_destroy_image(data->mlx, data->texture.augustin.img);
	if (data->texture.teddy_bear.img)
		mlx_destroy_image(data->mlx, data->texture.teddy_bear.img);
	if (data->texture.new_grass.img)
		mlx_destroy_image(data->mlx, data->texture.new_grass.img);
	if (data->texture.exit.img)
		mlx_destroy_image(data->mlx, data->texture.exit.img);
	if (data->texture.wall_down.img)
		mlx_destroy_image(data->mlx, data->texture.wall_down.img);
	if (data->texture.wall_up.img)
		mlx_destroy_image(data->mlx, data->texture.wall_up.img);
	if (data->texture.wall_left.img)
		mlx_destroy_image(data->mlx, data->texture.wall_left.img);
	if (data->texture.wall_right.img)
		mlx_destroy_image(data->mlx, data->texture.wall_right.img);
	if (data->texture.corner_d_r.img)
		mlx_destroy_image(data->mlx, data->texture.corner_d_r.img);
	if (data->texture.corner_u_r.img)
		mlx_destroy_image(data->mlx, data->texture.corner_u_r.img);
	if (data->texture.corner_u_l.img)
		mlx_destroy_image(data->mlx, data->texture.corner_u_l.img);
	if (data->texture.corner_d_l.img)
		mlx_destroy_image(data->mlx, data->texture.corner_d_l.img);
}

void	endgame(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	destroy_mlx_imgs(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_dchar(data->map.map);
}

int	handle_exit_button(t_data *data)
{
	endgame(data);
	exit(0);
	return (0);
}

int	check_image_init(t_data *data)
{
	if (data->texture.augustin.img && data->texture.teddy_bear.img
		&& data->texture.new_grass.img
		&& data->texture.exit.img
		&& data->texture.wall_down.img
		&& data->texture.wall_up.img
		&& data->texture.wall_left.img
		&& data->texture.wall_right.img
		&& data->texture.corner_d_r.img
		&& data->texture.corner_u_r.img
		&& data->texture.corner_u_l.img
		&& data->texture.corner_d_l.img)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
 	t_data	data;

	++argv; // parametre (map) (on saute solong pour etre direct sur largument qui est la map)
	--argc; // argc = 1
	ft_memset(&data, 0, sizeof(data));
	if (ft_check_error(argc, argv, &data))
		return (1);
	data.mlx = mlx_init(); 
	if (!data.mlx)
		return (ft_free_dchar(data.map.map), 1);
	data.win = mlx_new_window(data.mlx, (data.map.x * TILE_SIZE), (data.map.y * TILE_SIZE), "Hello World");
	if (!data.win)
		return (endgame(&data), 1);	
	ultimate_image_init(&data);
	if (!check_image_init(&data))
		return (endgame(&data), 1);
	display_map(data);
	data.map.collectible = count_collectible(data);
	mlx_hook(data.win, 33, (1L<<5), \
		&handle_exit_button, &data);
	mlx_key_hook (data.win, &key_hook, &data);
	mlx_loop(data.mlx);
	endgame(&data);
	return (0);	
}