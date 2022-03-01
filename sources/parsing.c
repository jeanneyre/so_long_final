/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:03:08 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:06:45 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_ber(char *argv)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".ber";
	i = 0;
	j = 0;
	while (argv[i])
		i++;
	if (i < 5)
		return (1);
	i -= 4;
	while (argv[i])
	{
		if (argv[i] != ext[j])
		{
			return (1);
		}
		++i;
		++j;
	}
	return (0);
}

int	check_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C'
			|| line[i] == 'E' || line[i] == 'P')
			i++;
		else
			return (1);
	}
	return (0);
}

int	count_line_col(t_map *map, char *argv)
{
	int		fd;
	char	*line;

	map->y = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	line = NULL;
	line = get_next_line(fd);
	map->x = ft_strnlen(line);
	while (line)
	{
		map->y++;
		if (map->x != ft_strnlen(line))
		{
			ft_free(line);
			return (close(fd), 1);
		}	
		ft_free(line);
		line = get_next_line(fd);
	}
	ft_free(line);
	close(fd);
	return (0);
}

int	fill_map(t_data *data, char *path)
{
	int	i;
	int	fd;

	fd = open(path, O_RDONLY | __O_NOFOLLOW);
	if (fd < 0)
		return (1);
	data->map.map = ft_calloc(data->map.y + 1, sizeof(char *));
	if (!data->map.map)
		return (close(fd), 1);
	i = -1;
	while (++i < data->map.y)
		data->map.map[i] = get_next_line(fd);
	data->map.map[i] = 0;
	close(fd);
	return (0);
}

int	directory_check(char *argv)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
	if (fd > 0)
		return (close(fd), 1);
	return (0);
}
