/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:31:53 by stabares          #+#    #+#             */
/*   Updated: 2024/12/09 17:53:36 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 || size == 0)
		return (ft_strdup(""));
	p = malloc(nmemb * size);
	if (!p)
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}

/* int	main(void)
{
	char	*buffer;

	buffer = NULL;
	printf("Antes de ft_calloc: \"%s\"\n", buffer);
	buffer = ft_calloc(5,10);
	printf("Despues de ft_calloc: \"%s\"\n", buffer);
	free(buffer);
	return (0);
} */