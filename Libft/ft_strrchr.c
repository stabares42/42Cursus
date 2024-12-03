/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:34:42 by stabares          #+#    #+#             */
/*   Updated: 2024/12/03 17:34:46 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	size_f	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i > 0)
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
		i--;
	}
	return (NULL);
}

int	main(void)
{
	const char	*str1;
	char		*result;
	
	ft_strlcpy(str1, "Hola, mundo");
	result = ft_strrchr(str1, 'n');
	if (result != NULL)
	{
		printf("Ultima aparición de 'n encontrada en la dirección: %p\n",result);
		printf("El Valor en esa dirección es: %c\n", *result);
	}
	else
	{
		printf("No se encontró el caracter 'z'.\n")
	}
	return (0);
}