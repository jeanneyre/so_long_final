/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:02:40 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:05:55 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_letters(t_data *data, int i)
{
	int	j;

	j = -1;
	while (data->map.map[i][++j])
	{
		if (data->map.map[i][j] == 'P')
		{
			data->player.player++;
			data->player.p_x = j;
			data->player.p_y = i;
		}
		else if (data->map.map[i][j] == 'C')
			data->collectible++;
		else if (data->map.map[i][j] == 'E')
			data->map.exit++;
	}
}

int	check_args(t_data *data)
{
	if (data->collectible < 1 || data->map.exit != 1
		|| data->player.player != 1)
		return (1);
	else
		return (0);
}

int	check_letters(t_data *data)
{
	int	i;

	i = -1;
	while (data->map.map[++i])
	{
		if (check_char(data->map.map[i]))
			return (1);
	}
	i = -1;
	while (data->map.map[++i])
		position_letters(data, i);
	return (check_args(data));
}

int	check_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_walls_around(t_data *data)
{
	int	i;

	i = -1;
	while (data->map.map[++i])
	{
		if (i == 0 || i == (data->map.y - 1))
		{
			if (check_wall(data->map.map[i]))
			{
				return (1);
			}
		}
		else if (i > 0 && i < data->map.y)
		{
			if (data->map.map[i][data->map.x - 1] != '1'
					|| data->map.map[i][0] != '1')
				return (1);
		}
	}
	return (0);
}
