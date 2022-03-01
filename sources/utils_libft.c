/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:22:28 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:06:57 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memset(void *string, int c, size_t n)
{
	char	*str;

	str = string;
	while (n)
	{
		*str = (unsigned char)c;
		str++;
		n--;
	}
	return (string);
}

void	ft_bzero(void *pointer, size_t count)
{
	ft_memset(pointer, '\0', count);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 && size == 0)
	{
		ptr = malloc(0);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	else
	{
		ptr = (char *)malloc(count * size);
		if (ptr == NULL)
			return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_putnbr(int n)
{
	unsigned int	i;
	char			a;

	i = n;
	if (n < 0)
	{
		write(1, "-", 1);
		i *= (-1);
	}
	while (i > 9)
	{
		ft_putnbr(i / 10);
		i %= 10;
	}
	a = '0' + i;
	write(1, &a, 1);
}
