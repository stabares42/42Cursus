/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:58:25 by stabares          #+#    #+#             */
/*   Updated: 2024/12/05 13:46:37 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big_str, const char *sub_str, size_t len)
{
	size_t	i;
	size_t	j;

	if (sub_str[0] == '\0')
		return ((char *)big_str);
	i = 0;
	while (big_str[i] != '\0' && i < len)
	{
		j = 0;
		while ((sub_str[j] != '\0') && (big_str[i + j] == sub_str[j])
			&& (i + j) < len)
			j++;
		if (sub_str[j] == '\0')
			return ((char *)&big_str[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	b_str[30];
	char	s_str[20];
	char	*result;

	strcpy(b_str, "Hola mundo, como estas.");
	strcpy(s_str, "mo");
	result = ft_strnstr(b_str, s_str, 20);
	if (result != NULL)
		printf("Palabra encontrada: \"%s\"\n", result);
	else
		printf("Palabra no encontrada.\n");
	return (0);
} */