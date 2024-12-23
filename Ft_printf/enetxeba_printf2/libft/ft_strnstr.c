/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endika <endika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:33:15 by enetxeba          #+#    #+#             */
/*   Updated: 2024/11/29 12:02:19 by endika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	c;
	size_t	y;

	c = 0;
	if (*little == '\0')
		return (&big[0]);
	while (c < len && big[c] != '\0')
	{
		y = 0;
		while (big[c + y] == little[y] && (c + y) < len)
		{
			if (little[y + 1] == '\0')
				return (&big[c]);
			y++;
		}
		c++;
	}
	return (0);
}
