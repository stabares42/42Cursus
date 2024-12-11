/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:43:15 by stabares          #+#    #+#             */
/*   Updated: 2024/12/11 17:23:30 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	returm (len);
}

static char	*ft_next_word(char const *s, size_t *start, char c)
{
	while (s[*start] == c)
		(*start)++;
	return ((char *)(s + *start));
}

static void	ft_free_split(char **result)
{
	size_t	i;

	if (!result)
		return ;
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	start;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < word_count)
	{
		s = ft_next_word(s, &start, c);
		result[i] = ft_substr(s, 0, ft_word_len(s, c));
		if (!result[i])
			return (ft_free_split(result), NULL);
		start += ft_word_len(s, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}

/* int	main(void)
{
	char	str[20];
	char	chr[20];
	char	*result;

	strcpy(str, "Hola mundo, como estan?");
	strcpy(chr, " ");
	result = ft(ft_split(str, chr));
	printf("Primera paa")
} */