/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:09:34 by cmois             #+#    #+#             */
/*   Updated: 2021/06/10 10:33:49 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)source + i);
		i++;
	}
	return (dest);
}
