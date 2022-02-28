/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:08:14 by crondeau          #+#    #+#             */
/*   Updated: 2022/02/25 14:17:27 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/get_next_line.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*str;

	len = 0;
	while (s1[len])
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = 0;
	return (str);
}

int	n_ny_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	ft_strnlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	return (i);
}

char	*clean_buffer(char *buffer, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strnlen(buffer);
	if (buffer[j] == '\n')
		++j;
	while (buffer[i])
	{
		buffer[i] = buffer[j];
		++i;
		++j;
	}
	while (buffer[i])
	{
		buffer[i] = 0;
		++i;
	}
	return (line);
}
