/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:54:16 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:06:39 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	handle_exit_button(t_data *data)
{
	endgame(data);
	exit(0);
	return (0);
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
