/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enetxeba <enetxeba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:14:15 by enetxeba          #+#    #+#             */
/*   Updated: 2024/12/16 10:01:36 by enetxeba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	ini;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	ini = 0;
	end = len;
	while (s1[ini] != '\0' && ft_strchr(set, s1[ini]))
		ini++;
	while (end > ini && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, ini, (end - ini)));
}
