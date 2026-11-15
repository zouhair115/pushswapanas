/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login1 <login1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 12:00:00 by login1            #+#    #+#             */
/*   Updated: 2026/11/07 12:00:00 by login1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	fill(char **v, const char *s, char c, int words)
{
	int	i;
	int	len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		v[i] = ft_substr(s, 0, len);
		if (!v[i])
			return (-1);
		s += len;
		i++;
	}
	v[i] = NULL;
	return (0);
}

void	ft_free_split(char **v)
{
	int	i;

	i = 0;
	while (v && v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

char	**ft_split(const char *s, char c)
{
	char	**v;
	int		words;

	words = count_words(s, c);
	v = malloc(sizeof(char *) * (words + 1));
	if (!v)
		return (NULL);
	if (fill(v, s, c, words) < 0)
	{
		ft_free_split(v);
		return (NULL);
	}
	return (v);
}
