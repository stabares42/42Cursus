/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:08:01 by stabares          #+#    #+#             */
/*   Updated: 2024/11/27 18:08:03 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (n > 0)
	{
		i = 0;
		while (i < n - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/*
int	main(void)
{
	char	dest[20];
	char	src[20];
	size_t	n;
	size_t	result;
	int		i;

	i = 0;
	while (i < 20)
	{
		dest[i] = 0;
		i++;
	}
	strcpy(src, "Cadena de prueba");
	
	n = 20;
	result = ft_strlcpy(dest, src, n);
	printf("Origen: \"%s\"\n", src);
	printf("Destino: \"%s\"\n", dest);
	printf("Longitud de origen: \"%ld\"\n",result);

	n = 10;
	result = ft_strlcpy(dest, src, n);
	printf("Origen: \"%s\"\n", src);
	printf("Destino: \"%s\"\n", dest);
	printf("Longitud de origen: \"%ld\"\n",result);

	return (0);
}
*/
