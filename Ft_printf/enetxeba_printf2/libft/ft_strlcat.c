/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endika <endika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:27:01 by enetxeba          #+#    #+#             */
/*   Updated: 2024/11/29 12:02:19 by endika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	c;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	c = 0;
	if (len_dest >= size)
		return (size + len_src);
	else
	{
		while (src[c] != '\0' && len_dest + c < size -1)
		{
			dest[len_dest + c] = src [c];
			c++;
		}
		dest[len_dest + c] = '\0';
		return (len_dest + len_src);
	}
}
