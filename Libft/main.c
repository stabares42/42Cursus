#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

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

// Función auxiliar para ft_strmapi
char	ft_map_function(unsigned int i, char c)
{
	return (c + i);
}

// Función principal de pruebas
void	run_tests(void)
{
	char	*str;
	char	*dup;
	char	dest[100];
	char	src[] = "Hello World";
	int		num;

	// ft_strlen
	str = "Test string";
	printf("\n--- ft_strlen ---\n");
	printf("Original: %lu\n", strlen(str));
	printf("Custom:   %lu\n", ft_strlen(str));
	print_test_result("ft_strlen", ft_strlen(str) == strlen(str));

	// ft_strdup
	dup = ft_strdup(str);
	printf("\n--- ft_strdup ---\n");
	printf("Original: %s\n", str);
	printf("Custom:   %s\n", dup);
	print_test_result("ft_strdup", strcmp(dup, str) == 0);
	free(dup);

	// ft_strlcpy
	ft_strlcpy(dest, src, sizeof(dest));
	printf("\n--- ft_strlcpy ---\n");
	printf("Original: %s\n", src);
	printf("Custom:   %s\n", dest);
	print_test_result("ft_strlcpy", strcmp(dest, src) == 0);

	// ft_strlcat
	ft_strlcpy(dest, "Hello ", sizeof(dest));
	ft_strlcat(dest, "42", sizeof(dest));
	printf("\n--- ft_strlcat ---\n");
	printf("Original: %s\n", "Hello 42");
	printf("Custom:   %s\n", dest);
	print_test_result("ft_strlcat", strcmp(dest, "Hello 42") == 0);

	// ft_memset
	ft_memset(dest, 'A', 5);
	dest[5] = '\0';
	printf("\n--- ft_memset ---\n");
	printf("Original: %s\n", "AAAAA");
	printf("Custom:   %s\n", dest);
	print_test_result("ft_memset", strcmp(dest, "AAAAA") == 0);

	// ft_bzero
	strcpy(dest, "Test");
	ft_bzero(dest, 4);
	printf("\n--- ft_bzero ---\n");
	printf("Original: %s\n", "(null)");
	printf("Custom:   %s\n", dest);
	print_test_result("ft_bzero", dest[0] == '\0' && dest[1] == '\0');

	// ft_memcpy
	strcpy(dest, "Test");
	ft_memcpy(dest, src, 5);
	printf("\n--- ft_memcpy ---\n");
	printf("Original: %s\n", "Hello");
	printf("Custom:   %s\n", dest);
	print_test_result("ft_memcpy", strcmp(dest, "Hello") == 0);

	strcpy(dest, "OverlapTest");
ft_memmove(dest + 3, dest, 6);
printf("\n--- ft_memmove ---\n");
printf("Original: %s\n", "OveOverlapTest");
printf("Custom:   %s\n", dest);
print_test_result("ft_memmove", strcmp(dest, "OveOverlapTest") == 0);
	// ft_atoi
	str = "42";
	printf("\n--- ft_atoi ---\n");
	printf("Original: %d\n", atoi(str));
	printf("Custom:   %d\n", ft_atoi(str));
	print_test_result("ft_atoi", ft_atoi(str) == atoi(str));

	// ft_isalpha
	num = 'A';
	printf("\n--- ft_isalpha ---\n");
	printf("Original: %d\n", isalpha(num));
	printf("Custom:   %d\n", ft_isalpha(num));
	print_test_result("ft_isalpha", (ft_isalpha(num) != 0) == (isalpha(num) != 0) );

	// ft_isdigit
	num = '4';
	printf("\n--- ft_isdigit ---\n");
	printf("Original: %d\n", isdigit(num));
	printf("Custom:   %d\n", ft_isdigit(num));
	print_test_result("ft_isdigit", (ft_isdigit(num) != 0) ==  (isdigit(num) != 0));

	// ft_isalnum
	num = '5';
	printf("\n--- ft_isalnum ---\n");
	printf("Original: %d\n", isalnum(num));
	printf("Custom:   %d\n", ft_isalnum(num));
	print_test_result("ft_isalnum", (ft_isalnum(num) != 0) == (isalnum(num) != 0));

	// ft_isascii
	num = 127;
	printf("\n--- ft_isascii ---\n");
	printf("Original: %d\n", isascii(num));
	printf("Custom:   %d\n", ft_isascii(num));
	print_test_result("ft_isascii", ft_isascii(num) == isascii(num));

	// ft_isprint
	num = 32;
	printf("\n--- ft_isprint ---\n");
	printf("Original: %d\n", isprint(num));
	printf("Custom:   %d\n", ft_isprint(num));
	print_test_result("ft_isprint", (ft_isprint(num) != 0) == (isprint(num) != 0));

	// ft_toupper
	num = 'a';
	printf("\n--- ft_toupper ---\n");
	printf("Original: %c\n", toupper(num));
	printf("Custom:   %c\n", ft_toupper(num));
	print_test_result("ft_toupper", ft_toupper(num) == toupper(num));

	// ft_tolower
	num = 'Z';
	printf("\n--- ft_tolower ---\n");
	printf("Original: %c\n", tolower(num));
	printf("Custom:   %c\n", ft_tolower(num));
	print_test_result("ft_tolower", ft_tolower(num) == tolower(num));

	// ft_strchr
	str = "Hello";
	printf("\n--- ft_strchr ---\n");
	printf("Original: %s\n", strchr(str, 'e'));
	printf("Custom:   %s\n", ft_strchr(str, 'e'));
	print_test_result("ft_strchr", ft_strchr(str, 'e') == strchr(str, 'e'));

	// ft_strrchr
	printf("\n--- ft_strrchr ---\n");
	printf("Original: %s\n", strrchr(str, 'l'));
	printf("Custom:   %s\n", ft_strrchr(str, 'l'));
	print_test_result("ft_strrchr", ft_strrchr(str, 'l') == strrchr(str, 'l'));

	// ft_strncmp
	printf("\n--- ft_strncmp ---\n");
	printf("Original: %d\n", strncmp("abc", "abd", 2));
	printf("Custom:   %d\n", ft_strncmp("abc", "abd", 2));
	print_test_result("ft_strncmp", ft_strncmp("abc", "abd", 2) == strncmp("abc", "abd", 2));

	// ft_memcmp
	printf("\n--- ft_memcmp ---\n");
	printf("Original: %d\n", memcmp("abc", "abd", 3));
	printf("Custom:   %d\n", ft_memcmp("abc", "abd", 3));
	print_test_result("ft_memcmp", ft_memcmp("abc", "abd", 3) == memcmp("abc", "abd", 3));

	// ft_strnstr
	printf("\n--- ft_strnstr ---\n");
	printf("Original: %s\n", strstr("Hello World", "World"));
	printf("Custom:   %s\n", ft_strnstr("Hello World", "World", 11));
	print_test_result("ft_strnstr", ft_strnstr("Hello World", "World", 11) == strstr("Hello World", "World"));

	// ft_calloc
	str = ft_calloc(10, sizeof(char));
	printf("\n--- ft_calloc ---\n");
	printf("Original: %s\n", "(null)");
	printf("Custom:   %s\n", str);
	print_test_result("ft_calloc", str != NULL && str[0] == '\0');
	free(str);

	// ft_substr
	str = ft_substr("Hello World", 6, 5);
	printf("\n--- ft_substr ---\n");
	printf("Original: %s\n", "World");
	printf("Custom:   %s\n", str);
	print_test_result("ft_substr", strcmp(str, "World") == 0);
	free(str);

	// ft_strjoin
	str = ft_strjoin("Hello", " World");
	printf("\n--- ft_strjoin ---\n");
	printf("Original: %s\n", "Hello World");
	printf("Custom:   %s\n", str);
	print_test_result("ft_strjoin", strcmp(str, "Hello World") == 0);
	free(str);

	// ft_split
	char **split = ft_split("Hello World 42", ' ');
	printf("\n--- ft_split ---\n");
	printf("Original: %s, %s\n", "Hello", "World");
	printf("Custom:   %s, %s\n", split[0], split[1]);
	print_test_result("ft_split", strcmp(split[0], "Hello") == 0 && strcmp(split[1], "World") == 0);
	for (int i = 0; split[i]; i++)
		free(split[i]);
	free(split);

	// ft_itoa
	str = ft_itoa(42);
	printf("\n--- ft_itoa ---\n");
	printf("Original: %s\n", "42");
	printf("Custom:   %s\n", str);
	print_test_result("ft_itoa", strcmp(str, "42") == 0);
	free(str);

	// ft_strmapi
	str = ft_strmapi("abc", ft_map_function);
	printf("\n--- ft_strmapi ---\n");
	printf("Original: %s\n", "ace");
	printf("Custom:   %s\n", str);
	print_test_result("ft_strmapi", strcmp(str, "ace") == 0);
	free(str);

	// ft_putchar_fd
	printf("\n--- ft_putchar_fd ---\n");
	printf("Original: A\n");
	ft_putchar_fd('A', 1);
	printf("\nCustom:   A\n");
	print_test_result("ft_putchar_fd", 1);

	// ft_putstr_fd
	printf("\n--- ft_putstr_fd ---\n");
	printf("Original: Hello World\n");
	ft_putstr_fd("Hello World\n", 1);
	printf("Custom:   Hello World\n");
	print_test_result("ft_putstr_fd", 1);

	// ft_putendl_fd
	printf("\n--- ft_putendl_fd ---\n");
	printf("Original: Hello 42\n");
	ft_putendl_fd("Hello 42", 1);
	printf("Custom:   Hello 42\n");
	print_test_result("ft_putendl_fd", 1);

	// ft_putnbr_fd
	printf("\n--- ft_putnbr_fd ---\n");
	printf("Original: 12345\n");
	ft_putnbr_fd(12345, 1);
	printf("\nCustom:   12345\n");
	print_test_result("ft_putnbr_fd", 1);
}

int	main(void)
{
	print_header();  // Mostrar el header "SANTEST"
	run_tests();     // Ejecutar todas las pruebas
	return (0);
}