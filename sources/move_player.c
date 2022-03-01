/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:03:00 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:06:33 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_exit_opened(t_data *data)
{
	if (data->player.collected == data->map.collectible)
	{
		data->player.moove++;
		print_moves(data);
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
	data->player.p_y = i - 1;
	data->player.moove++;
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
	data->player.p_y = i + 1;
	data->player.moove++;
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
	data->player.p_x = j - 1;
	data->player.moove++;
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
	data->player.p_x = j + 1;
	data->player.moove++;
	print_moves(data);
}
