/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:05:00 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 13:41:53 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

/* int	main(void)
{
	char	str1[20];
	char	st[20];
	char	*result;

	strcpy(str1, "***Ho*la mundo++");
	strcpy(st, "*+");
	result = ft_strtrim(str1, st);
	printf("Primera cadena: \"%s\"\n", str1);
	printf("Segunda cadena: \"%s\"\n", st);
	printf("Cadena esperada: \"%s\"\n", result);
	return (0);
}*/