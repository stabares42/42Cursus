/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:16:32 by stabares          #+#    #+#             */
/*   Updated: 2024/12/17 18:33:39 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* int	main(void)
{
	char	str1[10];
	char	str2[1];
	char	str3[17];
	char	str4[11];

	strcpy(str1, "Hola, 42!");
	strcpy(str2, "");
	strcpy(str3, "Prueba ft_srtlen");
	strcpy(str4, "1234567890");
	printf("La longitud de \"%s\" es %zu\n", str1, ft_strlen(str1));
	printf("La longitud de \"%s\" es %zu\n", str2, ft_strlen(str2));
	printf("La longitud de \"%s\" es %zu\n", str3, ft_strlen(str3));
	printf("La longitud de \"%s\" es %zu\n", str4, ft_strlen(str4));
	return (0);
} */