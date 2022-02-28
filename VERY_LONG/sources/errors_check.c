
#include "../Headers/so_long.h"

void	position_letters(t_data *data, int i)
{
	int j;

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
	if (data->collectible < 1 || data->map.exit != 1 || data->player.player != 1)
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
	return (check_args(data)); // return 1 si les elements de la map sont pas valide et 0 si cest tout bon
}

int	check_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')	//rajout du != '\0'  && str[i + 1] != '\0' pas utile ou plus utile dans mes tests
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

int	error_code(t_data *data, int code)
{
	if (code == 1)
		printf("Wrong number of arguments\n");
	else if (code == 2)
		printf("Can build a map with a directory\n");
	else if (code == 3)
		printf("Make an effort, I only use .ber to build a map\n");
	else if (code == 4)
		printf("It have to be squarish, please, try to make a square...\n");
	if (code == 5)
		printf("Map recuperation failure\n");
	else if (code == 6)
		printf("You're so close !! Just surround map with 1 and you might be able to play.\n");
	if (code == 7)
		printf("Ok, final step and you can play, don't be foolish and just put P E C in the .ber\n");
	if (code == 8)
		printf("Image creation failed\n");
	ft_free_dchar(data->map.map);
	data->map.map = NULL;
	return (1);
}