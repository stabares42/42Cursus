/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:34:42 by stabares          #+#    #+#             */
/*   Updated: 2024/12/16 23:20:40 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i] == c)
		return ((char *)&str[i]);
	while (i > 0)
	{
		i--;
		if (str[i] == c)
			return ((char *)&str[i]);
	}
	return (NULL);
}

/* int	main(void)
{
	char	str1[50];
	char	*result;

	strcpy(str1, "Hola, mundo");
	result = ft_strrchr(str1, 'n');
	if (result != NULL)
	{
		printf("Ultima aparición de 'n encontrada en la dirección: %p\n",result);
		printf("El Valor en esa dirección es: %c\n", *result);
	}
	else
	{
		printf("No se encontró el caracter 'z'.\n");
	}
	return (0);
} */