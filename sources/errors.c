/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:37:49 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:06:12 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_error(int argc, char **argv, t_data *data)
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

int	error_code(t_data *data, int code)
{
	if (code == 1)
		write(2, "Error\n", ft_strlen("Error\n"));
	else if (code == 2)
		write(2, "Error\n", ft_strlen("Error\n"));
	else if (code == 3)
		write(2, "Error\n", ft_strlen("Error\n"));
	else if (code == 4)
		write(2, "Error\n", ft_strlen("Error\n"));
	if (code == 5)
		write(2, "Error\n", ft_strlen("Error\n"));
	else if (code == 6)
		write(2, "Error\n", ft_strlen("Error\n"));
	if (code == 7)
		write(2, "Error\n", ft_strlen("Error\n"));
	if (code == 8)
		write(2, "Image creation failed\n",
			ft_strlen("Image creation failed\n"));
	ft_free_dchar(data->map.map);
	data->map.map = NULL;
	return (1);
}
