/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endika <endika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:47 by enetxeba          #+#    #+#             */
/*   Updated: 2024/11/29 12:53:38 by endika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	if (dest == src || !n)
		return (dest);
	dest_ptr = (char *) dest;
	src_ptr = (const char *) src;
	if (dest_ptr > src_ptr && dest_ptr < src_ptr + n)
	{
		while (n--)
			*(dest_ptr + n) = *(src_ptr + n);
	}
	else
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	return (dest);
}
