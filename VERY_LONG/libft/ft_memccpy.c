/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:09:17 by cmois             #+#    #+#             */
/*   Updated: 2021/06/10 10:33:38 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
		if (((unsigned char *)source)[i] == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
