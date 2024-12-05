/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:00:49 by stabares          #+#    #+#             */
/*   Updated: 2024/12/05 13:17:22 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = b;
	while (i < n)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/* int	main(void)
{
	char	buffer[20];
	size_t	n;
	int		fill_char; 
	size_t	i;

	n = 10;
	fill_char = '*';
	i = 0;
	while (i < 19)
	{
		buffer[i] = '.';
		i++;
	}
	buffer[19] = '\0';
	printf("Antes de ft_memset: \"%s\"\n", buffer);
	ft_memset(buffer, fill_char, n);
	// buffer[n] = '\0';
	printf("Despues de ft_memset: \"%s\"\n", buffer);
	return (0);
} */
