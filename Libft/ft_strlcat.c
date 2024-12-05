/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:00:24 by stabares          #+#    #+#             */
/*   Updated: 2024/12/05 13:35:41 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	src_len = strlen(src);
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while (i + dst_len + 1 < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* int	main(void)
{
	char	dst[15];
	char	src[15];
	size_t	buffer_size;
	size_t	result;

	buffer_size = 20;
	strcpy(dst, "Hola ");
	strcpy(src, "mundo");
	result = ft_strlcat(dst, src, buffer_size);
	printf("Cadena concatenada: \"%s\"\n", dst);
	printf("Longitud de cadena concatenada: \"%ld\"\n", result);
	return (0);
} */