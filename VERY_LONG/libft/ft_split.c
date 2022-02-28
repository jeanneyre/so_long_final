/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:06:19 by cmois             #+#    #+#             */
/*   Updated: 2021/10/20 08:54:23 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include <stdio.h>
#include <stdlib.h>

int	sizeword(char const *s, char c)
{
	int	size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

int	count_word(char const *s, char c)
{
	int	state;
	int	word;

	word = 0;
	state = 1;
	while (*s)
	{
		if (*s == c)
			state = 1;
		else
		{
			if (state == 1)
				word++;
			state = 0;
		}
		s++;
	}
	return (word);
}

char	**ft_free(char **s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		free(s[j]);
		j++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (s == 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * count_word(s, c) + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (count_word(s, c))
	{
		while (*s && *s == c)
			s++;
		tab[i] = (char *)malloc(sizeof(char) * sizeword(s, c) + 1);
		if (!tab[i])
			return (ft_free(tab));
		j = 0;
		while (*s && *s != c)
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
