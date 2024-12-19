/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:28:19 by stabares          #+#    #+#             */
/*   Updated: 2024/12/19 14:36:30 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (s && s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

/* int	main()
{
	char *str = "Hola mundo";

	ft_putstr_fd(str, 1);
	return (0);
}*/