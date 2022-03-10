/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:43:39 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/02 09:46:36 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_wall(t_data *data, int i, int j)
{
	if (i == 0 && (j > 0 && j < (data->map.x - 1)))
		mlx_put_image_to_window(data->mlx, data->win, data->texture.wall_up.img,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (j == 0 && (i > 0 && i < (data->map.y - 1)))
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.wall_left.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (j == (data->map.x - 1) && (i > 0 && i < (data->map.y - 1)))
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.wall_right.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (i == (data->map.y - 1) && j == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.corner_d_l.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (i == 0 && j == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.corner_u_l.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (i == 0 && j == (data->map.x - 1))
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.corner_u_r.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (i == (data->map.y - 1) && j == (data->map.x - 1))
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.corner_d_r.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (i == (data->map.y - 1) && (j > 0 && j < (data->map.x - 1)))
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.wall_down.img, j * TILE_SIZE, i * TILE_SIZE);
}

void	parsing_display(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == '1')
	{
		render_wall(data, i, j);
		if ((i > 0 && i < (data->map.y - 1))
			&& (j > 0 && j < (data->map.x - 1)))
			mlx_put_image_to_window(data->mlx, data->win,
				data->texture.buisson.img, j * TILE_SIZE, i * TILE_SIZE);
	}
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.new_grass.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.teddy_bear.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.augustin.img, j * TILE_SIZE, i * TILE_SIZE);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->texture.exit.img, j * TILE_SIZE, i * TILE_SIZE);
}

void	print_moves(t_data *data)
{
	write(1, "\E[H\E[2J", ft_strlen("\E[H\E[2J"));
	write(1, YELLOW, ft_strlen(YELLOW));
	write(1, "         Moves counter : ",
		ft_strlen("         Moves counter : "));
	ft_putnbr(data->player.moove);
	write(1, "\n", ft_strlen("\n"));
	write(1, RESET, ft_strlen(RESET));
}

int	count_collectible(t_data data)
{
	int	i;
	int	j;
	int	c;

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
	int	i;
	int	j;

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
