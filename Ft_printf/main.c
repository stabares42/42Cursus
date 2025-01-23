/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:40:50 by stabares          #+#    #+#             */
/*   Updated: 2025/01/23 15:47:24 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#define DELAY 50000  // Retardo en microsegundos

// Colores ANSI
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

// Función para mostrar el header "SANTEST" en grande y en verde
void	print_header(void)
{
	const char *header[] = {
		"+-----------------------------------------------------------+",
		"| ███████  █████  ██   ██ ████████ ███████ ███████ ████████ |",
		"|░██░░░░  ██░░░██░███ ░██░░░░██   ░██░░░░ ░██░░░░ ░░░░██    |",
		"|░███████░██  ░██░████░██   ░██   ░███████░███████   ░██    |",
		"|    ░░██░███████░██░████   ░██   ░██░░░░     ░░██   ░██    |",
		"| ███████░██  ░██░██ ░░██   ░██   ░███████ ███████   ░██    |",
		"|░░░░░░░ ░░   ░░ ░░   ░░    ░░    ░░░░░░░ ░░░░░░░    ░░     |",
		"+-----------------------------------------------------------+"
	};

	printf(GREEN);  // Cambiar color a verde
	int i = 0;
	while (header[i])
	{
		printf("%s\n", header[i]);
		fflush(stdout);
		usleep(DELAY);
		i++;
	}
	printf(RESET);  // Restablecer color
	printf("\n\n");
}

// Función para mostrar resultados de los tests con retardo y colores
void	print_test_result(const char *test_name, int result)
{
	printf("Testing %s... ", test_name);
	fflush(stdout);
	usleep(DELAY);

	if (result)
		printf(GREEN "[OK]\n" RESET);
	else
		printf(RED "[KO]\n" RESET);
}

void	test_characters(void)
{
	char c = 'A';
	
	printf("\n--- Character Tests ---\n");
	printf("Original: %c\n", c);
	ft_printf("Custom:   %c\n", c);
	printf("Original: %c\n", 'S');
	ft_printf("Custom:   %c\n", 'S');
	print_test_result("ft_printf characters", 1);
}

void	test_strings(void)
{
	char *str = "Hello, 42!";
	char *str_null = NULL;
	
	printf("\n--- String Tests ---\n");
	printf("Original: %s\n", str);
	ft_printf("Custom:   %s\n", str);
	printf("Original: %s\n", "Hello, 42!");
	ft_printf("Custom:   %s\n", "Hello, 42!");
	printf("Original (NULL): %s\n", str_null ? str_null : "(null)");
	ft_printf("Custom (NULL):   %s\n", str_null);
	print_test_result("ft_printf strings", 1);
}

void test_integers(void)
{
    int num = 42;
    int num_neg = -42;
    int max_int = INT_MAX;
    int min_int = INT_MIN;

    printf("\n--- Integer Tests ---\n");
    printf("Original (d): %d\n", num);
    ft_printf("Custom (d):   %d\n", num);
    printf("Original (d, negative): %d\n", num_neg);
    ft_printf("Custom (d, negative):   %d\n", num_neg);
    printf("Original (i): %i\n", num);
    ft_printf("Custom (i): %i\n", num);
	printf("Original (i, negative): %i\n", num_neg);
    ft_printf("Custom (i, negative):   %i\n", num_neg);
    printf("Original (d)(INT_MAX): %d\n", max_int);
    ft_printf("Custom (d)(INT_MAX):   %d\n", max_int);
    printf("Original (d)(INT_MIN): %d\n", min_int);
    ft_printf("Custom (d)(INT_MIN):   %d\n", min_int);
	printf("Original (i)(INT_MAX): %i\n", max_int);
    ft_printf("Custom (i)(INT_MAX):   %i\n", max_int);
    printf("Original (i)(INT_MIN): %i\n", min_int);
    ft_printf("Custom (i)(INT_MIN):   %i\n", min_int);
	print_test_result("ft_printf integers", 1);
}

void	test_unsigned(void)
{
	unsigned int u_num = 42;
	unsigned int u_num_neg = -42;
	
	printf("\n--- Unsigned Integer Tests ---\n");
	printf("Original: %u\n", u_num);
	ft_printf("Custom:   %u\n", u_num);
	printf("Original (u, negative): %u\n", u_num_neg);
	ft_printf("Custom (u, negative):   %u\n", u_num_neg);
	print_test_result("ft_printf unsigned", 1);
}

void	test_hexadecimal(void)
{
	unsigned int hex = 42;
	unsigned int hex_neg = -42;
	
	printf("\n--- Hexadecimal Tests ---\n");
	printf("Original (lowercase): %x\n", hex);
	ft_printf("Custom (lowercase):   %x\n", hex);
	printf("Original (uppercase): %X\n", hex);
	ft_printf("Custom (uppercase):   %X\n", hex);
	printf("Original negative(lowercase): %x\n", hex_neg);
	ft_printf("Custom negative(lowercase):   %x\n", hex_neg);
	printf("Original negative(uppercase): %X\n", hex_neg);
	ft_printf("Custom negative(uppercase):   %X\n", hex_neg);
	print_test_result("ft_printf hexadecimal", 1);
}

void	test_pointers(void)
{
	char *ptr = "42 School";
	
	printf("\n--- Pointer Tests ---\n");
	printf("Original: %p\n", (void *)ptr);
	ft_printf("Custom:   %p\n", (void *)ptr);
	printf("Original (NULL): %p\n", NULL);
	ft_printf("Custom (NULL):   %p\n", NULL);
	print_test_result("ft_printf pointers", 1);
}

void	test_percent(void)
{
	printf("\n--- Percent Sign Tests ---\n");
	printf("Original: %%\n");
	ft_printf("Custom:   %%\n");
	print_test_result("ft_printf percent", 1);
}

void	test_combined(void)
{
	int	num = 42;
	int	neg_num = -42;
	char *str = "combined";
	char chr = 'S';
	
	printf("\n--- Combined Tests ---\n");
	printf("Original: %c %s %d %i %u %x %X  %p %%\n", 
	chr, str, num, num, neg_num, num, num, str);
	ft_printf("Custom: %c %s %d %i %u %x %X  %p %%\n", 
	chr, str, num, num, neg_num, num, num, str);
	print_test_result("ft_printf combined", 1);
}

void	test_count(void)
{
	printf("\n--- Character Count Tests ---\n");
	int original_count = printf("Original count test: %d, %s\n", 123, "abc");
	int custom_count = ft_printf("Custom count test:   %d, %s\n", 123, "abc");
	
	printf("Original returned: %d\n", original_count);
	printf("Custom returned:   %d\n", custom_count);
	print_test_result("ft_printf count", original_count == custom_count);
}

int	main(void)
{
	print_header();
	test_characters();
	test_strings();
	test_integers();
	test_unsigned();
	test_hexadecimal();
	test_pointers();
	test_percent();
	test_combined();
	test_count();

	return (0);
}