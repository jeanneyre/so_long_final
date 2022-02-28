/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:07:28 by cmois             #+#    #+#             */
/*   Updated: 2021/06/06 14:56:56 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				j;
	char			*ptr;

	if (s && f)
	{
		i = 0;
		j = ft_strlen((char *)s);
		ptr = (char *)malloc(sizeof(char) * j + 1);
		if (ptr == NULL)
			return (NULL);
		while (s[i])
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	else
		return (NULL);
}
