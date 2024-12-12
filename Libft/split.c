/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:03:54 by stabares          #+#    #+#             */
/*   Updated: 2024/12/12 12:03:08 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	int		in_word;
	size_t	count;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
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

static char	*ft_get_word(char const *s, size_t start, size_t len)
{
	char	*word;
	size_t	index;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	index = 0;
	while (index < len)
	{
		word[index] = s[start + index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

static char	**ft_free_all(char **result, size_t i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
	return (NULL);
}

static size_t	ft_find_next(char const *s, size_t *start, char c)
{
	size_t	end;

	while (s[*start] && s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] && s[end] != c)
		end++;
	return (end);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	start = 0;
	i = 0;
	while (i < words)
	{
		end = ft_find_next(s, &start, c);
		result[i] = ft_get_word(s, start, end - start);
		if (!result[i++])
			return (ft_free_all(result, i - 1));
		start = end;
	}
	result[i] = NULL;
	return (result);
}

int	main(void)
{
	char	**words;
	char	str[50];
	char	delimiter;
	size_t	i;

	strcpy(str, "Hola mundo, como estan?");
	delimiter = ' ';
	words = ft_split(str, delimiter);
	if (!words)
	{
		printf("Error al dividir la cadena.\n");
		return (1);
	}
	printf("Cadena a dividir \"%s\"\n", str);
	i = 0;
	while (words[i])
	{
		printf("Palabra %zu: \"%s\"\n", i + 1, words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
