/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:10:23 by stabares          #+#    #+#             */
/*   Updated: 2024/12/10 12:49:52 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char	buffer_dest[20];
	char	buffer_src[] = "Cadena de prueba";
	int		i;

	i = 0;
	while (i < 20)
	{
		buffer_dest[i] = 0;
		i++;
	}
	printf("Antes de memcpy.\n");
	printf("Origen: \"%s\"\n", buffer_src);
	printf("Destino: \"%s\"\n", buffer_dest);

	ft_memcpy(buffer_dest, buffer_src, 13);

	printf("Después de memcpy:\n");
	printf("Origen: \"%s\"\n", buffer_src);
	printf("Destino: \"%s\"\n", buffer_dest);
	return (0);
} */