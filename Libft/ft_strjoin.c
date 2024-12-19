/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:59:52 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:34:18 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
	{
		result[i++] = *s1++;
	}
	while (*s2)
	{
		result[i++] = *s2++;
	}
	return (result);
}

/* int	main(void)
{
	char	str1[20];
	char	str2[20];
	char	*result;

	strcpy(str1, "Hola, ");
	strcpy(str2, "mundo");
	result = ft_strjoin(str1, str2);
	printf("Cadena uno: \"%s\"\n", str1);
	printf("Cadena dos: \"%s\"\n", str2);
	printf("Cadena nueva: \"%s\"\n", result);
	return (0);
}*/