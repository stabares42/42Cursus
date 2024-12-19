/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:25:41 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:44:38 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)b)[i] = 0;
		i++;
	}
}

/* int	main(void)
{
	char	buffer[27];

	strcpy(buffer, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	printf("Antes de bzero: \"%s\"\n", buffer);
	ft_bzero(buffer, 10);
	printf("Despues de bzero: \"%s\"\n", &buffer[10]);
	return (0);
}*/