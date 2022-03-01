/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:02:30 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:28:24 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		&& data->texture.corner_d_l.img
		&& data->texture.buisson.img)
		return (1);
	else
		return (0);
}

void	image_init(t_data *data, char *path, t_spritz *text)
{
	text->img = mlx_xpm_file_to_image(data->mlx, path, &text->width,
			&text->height);
	if (!text->img)
		error_code(data, 8);
}

void	ultimate_image_init2(t_data *data)
{
	image_init(data, "images/texture_environnement/corner_u_r.xpm",
		&data->texture.corner_u_r);
	image_init(data, "images/texture_environnement/corner_u_l.xpm",
		&data->texture.corner_u_l);
	image_init(data, "images/texture_environnement/buisson.xpm",
		&data->texture.buisson);
}

void	ultimate_image_init(t_data *data)
{
	image_init(data, "images/perso+collect/jouets/augustin.xpm",
		&data->texture.augustin);
	image_init(data, "images/perso+collect/jouets/teddy_bear.xpm",
		&data->texture.teddy_bear);
	image_init(data, "images/texture_environnement/new_grass.xpm",
		&data->texture.new_grass);
	image_init(data, "images/texture_environnement/exit.xpm",
		&data->texture.exit);
	image_init(data, "images/texture_environnement/wall_down.xpm",
		&data->texture.wall_down);
	image_init(data, "images/texture_environnement/wall_up.xpm",
		&data->texture.wall_up);
	image_init(data, "images/texture_environnement/wall_left.xpm",
		&data->texture.wall_left);
	image_init(data, "images/texture_environnement/wall_right.xpm",
		&data->texture.wall_right);
	image_init(data, "images/texture_environnement/corner_d_l.xpm",
		&data->texture.corner_d_l);
	image_init(data, "images/texture_environnement/corner_d_r.xpm",
		&data->texture.corner_d_r);
	ultimate_image_init2(data);
}
