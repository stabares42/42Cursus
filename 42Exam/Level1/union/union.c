/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:43:38 by stabares          #+#    #+#             */
/*   Updated: 2025/02/21 17:05:14 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	check(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	print_union(char *str1, char str2)
{
	int		i;
	int		j;
	char	printed[256] = {0};
	
	i = 0;
	while (str1[i])
	{
		if(!check(str2, str1[i]) && !printed[(unsigned char)str1[i]])
		{
			write(1, &str1[i], 1);
		{
		i++;
	}
	j = 0;
	while (str2[j])
	{
		if (!check(str1, str2[j]) && !check(str2, str2[j]))
			write(1, &str2[j], 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		print_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}