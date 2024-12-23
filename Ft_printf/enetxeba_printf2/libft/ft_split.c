/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:18:27 by enetxeba          #+#    #+#             */
/*   Updated: 2024/12/16 10:03:39 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search_n_parts(char const *s, char c)
{
	int	cnt;
	int	inside;

	cnt = 0;
	inside = 0;
	while (*s != '\0')
	{
		if (*s != c && inside == 0)
		{
			inside = 1;
			cnt++;
		}
		else if (*s == c)
			inside = 0;
		s++;
	}
	return (cnt);
}

static size_t	len_to_next(char const *s, char c, int ini)
{
	int	i;

	i = ini;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i - ini);
}

static void	*destroi(char **res, int i)
{
	while (--i >= 0)
		free(res[i]);
	free (res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		num_sub;
	int		i;
	int		ini;

	if (!s)
		return (NULL);
	num_sub = search_n_parts (s, c);
	res = malloc (sizeof(char *) * (num_sub + 1));
	if (!res || !s)
		return (NULL);
	i = 0;
	ini = 0;
	while (i < num_sub && s[ini] != '\0')
	{
		while (s[ini] == c)
			ini++;
		res[i] = ft_substr(s, ini, len_to_next(s, c, ini));
		if (!res[i])
			return (destroi(res, i));
		ini += len_to_next(s, c, ini);
		i++;
	}
	res[i] = NULL;
	return (res);
}
