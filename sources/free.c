/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:30:20 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:30:26 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(void *tofree)
{
	if (tofree)
		free(tofree);
	tofree = NULL;
}

int	ft_free_dchar(char **str)
{
	int	i;

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

void	destroy_mlx_imgs2(t_data *data)
{
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
	if (data->texture.buisson.img)
		mlx_destroy_image(data->mlx, data->texture.buisson.img);
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
	destroy_mlx_imgs2(data);
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
