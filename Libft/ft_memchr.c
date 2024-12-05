/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:27:58 by stabares          #+#    #+#             */
/*   Updated: 2024/12/05 12:47:24 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	unsigned char	*s;
	unsigned char	c;
	size_t			i;

	i = 0;
	s = (unsigned char *)str;
	c = (unsigned char )ch;
	while (i < n)
	{
		if (s[i] == c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[20];
	char	ch;
	void	*result;

	strcpy(str, "Hola mundo");
	ch = 'm';
	result = ft_memchr(str, ch, 10);
	if (result)
		printf("Esta el caracter \"%c\" en la direccion: %p\n", ch, result);
	else
		printf("No se encontro el caracter \"%c\"\n", ch);
	return (0);
} */