/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:04:50 by cmois             #+#    #+#             */
/*   Updated: 2021/05/26 11:39:00 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*ptr;

	if (nmemb == 0 && size == 0)
	{
		ptr = malloc(0);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	else
	{	
		ptr = (char *)malloc(nmemb * size);
		if (ptr == NULL)
			return (NULL);
	}
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
