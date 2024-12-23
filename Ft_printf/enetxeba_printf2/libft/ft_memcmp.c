/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endika <endika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:15:24 by enetxeba          #+#    #+#             */
/*   Updated: 2024/11/29 13:54:12 by endika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;

	if (!n)
		return (0);
	c = 0;
	while (c < n)
	{
		if (*((unsigned char *) s1 + c) != *((unsigned char *) s2 + c))
			return (*((unsigned char *) s1 + c) - *((unsigned char *) s2 + c));
		c++;
	}
	return (0);
}
