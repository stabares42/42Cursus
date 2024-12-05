/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:49:54 by stabares          #+#    #+#             */
/*   Updated: 2024/12/05 13:45:12 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	s1[20];
	char	s2[20];
	int		n;
	int		result;

	strcpy(s1, "Hola mundo");
	strcpy(s2, "Hola world");
	n = 7;
	result = ft_strncmp(s1, s2, n);
	printf("Resultado de ft_strncmp: %d\n", result);
	return (0);
} */