/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:29:53 by stabares          #+#    #+#             */
/*   Updated: 2024/12/05 15:41:49 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *ptr1, const void *ptr2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = ((unsigned char *)ptr1);
	p2 = ((unsigned char *)ptr2);
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	str1[50];
	char	str2[50];
	char	str3[50];
	int		result;

	strcpy(str1, "Hola");
	strcpy(str2, "Hola");
	strcpy(str3, "Hola mundo");
	result = ft_memcmp(str1, str2, 4);
	printf("Comparacion de str1 y str2: \"%d\"\n", result);
	result = ft_memcmp(str1, str3, 4);
	printf("Comparacion de str1 y str3: \"%d\"\n", result);
	result = ft_memcmp(str1, str3, 5);
	printf("Comparacion de str1 y str3: \"%d\"\n", result);
	return (0);
} */