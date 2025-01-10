/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:29:13 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:36:22 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

/* int	main(void)
{
	char	str[50];
	char	*result;
	size_t	buffer_size;

	buffer_size = 20;
	strncpy(str, "Hola, mundo!", buffer_size);
	str [buffer_size - 1] = '\0';
	result = ft_strchr(str, 'm');
	if (result)
	{
		printf("Se encontro el caracter 'm' en dirección: %p\n", result);
		printf("El valor en esa dirección: %c\n", *result);
	}
	else
		printf("No se encontro 'm'.\n");
	return (0);
}*/