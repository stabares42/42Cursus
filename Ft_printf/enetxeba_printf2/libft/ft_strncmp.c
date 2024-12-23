/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endika <endika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:40:38 by enetxeba          #+#    #+#             */
/*   Updated: 2024/11/29 13:09:20 by endika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	if (n == 0)
		return (0);
	c = 0;
	while (c < n)
	{
		if (s1[c] == s2[c] && s1[c])
		{
			while (s1[c] == s2[c] && s1[c] && c < n)
				c++;
		}
		else
			return ((unsigned char)s1[c] - (unsigned char) s2[c]);
	}
	return (0);
}
