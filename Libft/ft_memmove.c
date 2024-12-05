/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:04:30 by stabares          #+#    #+#             */
/*   Updated: 2024/12/05 13:13:40 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest < src)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		if (!n || dest == src)
			return (dest);
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

/* int	main(void)
{
	char	buffer_dest[50];
	char	buffer_src[50];
	size_t	i;

	strcpy(buffer_src, "Cadena de prueba!");
	i = 0;
	while (i < 50)
	{
		buffer_dest[i] = 0;
		i++;
	}
	printf("Antes de memmove.\n");
	printf("Origen: \"%s\"\n", buffer_src);
	printf("Destino: \"%s\"\n", buffer_dest);
	ft_memmove(buffer_dest, buffer_src, 5);
	printf("Antes de memmove.\n");
	printf("Origen: \"%s\"\n", buffer_src);
	printf("Destino: \"%s\"\n", buffer_dest);
	return (0);
}
 */