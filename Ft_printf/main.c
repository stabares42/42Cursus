/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:26:13 by stabares          #+#    #+#             */
/*   Updated: 2025/01/11 15:39:13 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h" 
# include <stdio.h>
# include <stddef.h>


int main(void)
{
	char *str = "HOLA";
	
    printf("Character test original: %c\n", 'S');
    ft_printf("Character test: %c\n", 'S');
    printf("String test original: %s\n", "42 is amazing!");
    ft_printf("String test: %s\n", "42 is amazing!");
	printf("Null string test original: %p\n", NULL);
    ft_printf("Null string test: %p\n", NULL);
    printf("Digit test original: %d\n", 42);
    ft_printf("Digit test: %d\n", 42);
    printf("Integer test orginal: %i\n", -42);
    ft_printf("Integer test: %i\n", -42);
    printf("Unsigned test original: %u\n", 42);
    ft_printf("Unsigned test: %u\n", 42);
    printf("Hexadecimal test original: (uppercase): %X\n", 222);
    ft_printf("Hexadecimal test (uppercase): %X\n", 222);
    printf("Hexadecimal test original: (lowercase): %x\n", 222);
    ft_printf("Hexadecimal test (lowercase): %x\n", 222);
    printf("Pointer test original: %p\n", &str);
    ft_printf("Pointer test: %p\n", &str);
	printf("Percent test original: %%\n");
	ft_printf("Percent test: %%\n");
	return (0);
}