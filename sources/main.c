/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:02:48 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:06:05 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	++argv;
	--argc;
	ft_memset(&data, 0, sizeof(data));
	if (ft_check_error(argc, argv, &data))
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_free_dchar(data.map.map), 1);
	data.win = mlx_new_window(data.mlx, (data.map.x * TILE_SIZE),
			(data.map.y * TILE_SIZE), "SO LONG");
	if (!data.win)
		return (endgame(&data), 1);
	ultimate_image_init(&data);
	if (!check_image_init(&data))
		return (endgame(&data), 1);
	display_map(data);
	data.map.collectible = count_collectible(data);
	mlx_hook(data.win, 33, (1L << 5),
		&handle_exit_button, &data);
	mlx_key_hook (data.win, &key_hook, &data);
	mlx_loop(data.mlx);
	endgame(&data);
	return (0);
}
