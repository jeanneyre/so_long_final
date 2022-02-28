/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:09:47 by cmois             #+#    #+#             */
/*   Updated: 2021/06/10 10:34:01 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *string, int c, size_t n)
{
	char	*str;

	str = string;
	while (n)
	{
		*str = (char)c;
		str++;
		n--;
	}
	return (string);
}
