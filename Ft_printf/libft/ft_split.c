/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:43:15 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:36:26 by stabares         ###   ########.fr       */
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

static size_t	ft_find_next_word(char const *s, size_t *start, char c)
{
	size_t	end;

	while (s[*start] && s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] && s[end] != c)
		end++;
	return (end);
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
	size_t	words;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	start = 0;
	i = 0;
	while (i < words)
	{
		end = ft_find_next_word(s, &start, c);
		result[i] = ft_substr(s, start, end - start);
		if (!result[i])
			return (ft_free_split(result), NULL);
		start = end;
		i++;
	}
	result[i] = NULL;
	return (result);
}
/* 
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
}*/