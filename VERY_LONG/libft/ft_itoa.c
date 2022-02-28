/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:04:59 by cmois             #+#    #+#             */
/*   Updated: 2021/10/15 10:39:04 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intl(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (++i);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	i;
	int		len;

	i = n;
	len = ft_intl(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (i == 0)
		str[0] = 48;
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	while (i > 0)
	{
		str[len--] = (i % 10) + '0';
		i /= 10;
	}
	return (str);
}
