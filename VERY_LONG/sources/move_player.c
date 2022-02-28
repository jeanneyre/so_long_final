#include "../Headers/so_long.h"

//////////en cours ///////

void	parsing_display(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == '1')
		render_wall(data, i, j);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->texture.new_grass.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->texture.teddy_bear.img, j * TILE_SIZE, i * TILE_SIZE);	
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->texture.augustin.img, j * TILE_SIZE, i * TILE_SIZE);	
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, \
		data->win, data->texture.exit.img, j * TILE_SIZE, i * TILE_SIZE);
}

void	print_moves(t_data *data)
{
	write(1, "\E[H\E[2J", ft_strlen("\E[H\E[2J"));
	write(1, GREEN, ft_strlen(GREEN));
	printf("         Moves counter : %d\n", data->player.player);
	write(1, RESET, ft_strlen(RESET));
}

int	is_exit_opened(t_data *data)
{
	if (data->player.collected == data->map.collectible)
	{
		endgame(data);
		exit(0);
	}
	else
		return (1);
}

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = data->player.p_y;
	j = data->player.p_x;
	if (data->map.map[i - 1][j] == '1')
		return ;
	if (data->map.map[i - 1][j] == 'E')
	{
		if (is_exit_opened(data) == 1)
			return ;
	}
	data->map.map[i][j] = '0';
	if (data->map.map[i - 1][j] == 'C')
		data->player.collected++;
	data->map.map[i - 1][j] = 'P';
	data->player.p_y= i - 1;
	data->player.player++;
	print_moves(data); 
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = data->player.p_y;
	j = data->player.p_x;
	if (data->map.map[i + 1][j] == '1')
		return ;
	if (data->map.map[i + 1][j] == 'E')
	{
		if (is_exit_opened(data) == 1)
			return ;
	}
	data->map.map[i][j] = '0';
	if (data->map.map[i + 1][j] == 'C')
		data->player.collected++;
	data->map.map[i + 1][j] = 'P';
	data->player.p_y= i + 1;
	data->player.player++;
	print_moves(data); 
}

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = data->player.p_y;
	j = data->player.p_x;
	if (data->map.map[i][j - 1] == '1')
		return ;
	if (data->map.map[i][j - 1] == 'E')
	{
		if (is_exit_opened(data) == 1)
			return ;
	}
	data->map.map[i][j] = '0';
	if (data->map.map[i][j - 1] == 'C')
		data->player.collected++;
	data->map.map[i][j - 1] = 'P';
	data->player.p_x= j - 1;
	data->player.player++;
	print_moves(data); 
}

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = data->player.p_y;
	j = data->player.p_x;
	if (data->map.map[i][j + 1] == '1')
		return ;
	if (data->map.map[i][j + 1] == 'E')
	{
		if (is_exit_opened(data) == 1)
			return ;
	}
	data->map.map[i][j] = '0';
	if (data->map.map[i][j + 1] == 'C')
		data->player.collected++;
	data->map.map[i][j + 1] = 'P';
	data->player.p_x= j + 1;
	data->player.player++;
	print_moves(data); 
}

void	move_player(t_data *data, char keypress)
{
	if (keypress == 'w')
		move_up(data);
	if (keypress == 's')
		move_down(data);
	if (keypress == 'a')
		move_left(data);
	if (keypress == 'd')
		move_right(data);
	display_map(*data);	
}
