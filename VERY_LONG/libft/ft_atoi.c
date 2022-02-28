/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:59:00 by cmois             #+#    #+#             */
/*   Updated: 2021/05/27 12:01:39 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	ft_len_int(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	result = 0;
	if (ft_len_int((char *)str + i) > 19)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	return (result * sign);
}
