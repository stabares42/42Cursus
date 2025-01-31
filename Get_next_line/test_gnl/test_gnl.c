/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stabares <stabares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:47:37 by stabares          #+#    #+#             */
/*   Updated: 2025/01/31 15:56:49 by stabares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void run_test(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("Error: No se pudo abrir el archivo %s\n", filename);
        return;
    }

    char *line;
    int line_number = 1;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Línea %d: %s", line_number++, line);
        free(line);
    }

    close(fd);
}

int main(void) {
    // Prueba 1: Archivo vacío
    printf("Prueba 1: Archivo vacío\n");
    run_test("test_gnl/empty.txt");

    // Prueba 2: Archivo con una sola línea
    printf("\nPrueba 2: Archivo con una sola línea\n");
    run_test("test_gnl/single_line.txt");

    // Prueba 3: Archivo con múltiples líneas
    printf("\nPrueba 3: Archivo con múltiples líneas\n");
    run_test("test_gnl/multiple_lines.txt");

    // Prueba 4: Archivo con líneas vacías
    printf("\nPrueba 4: Archivo con líneas vacías\n");
    run_test("test_gnl/empty_lines.txt");

    // Prueba 5: Archivo con diferentes tamaños de buffer
    printf("\nPrueba 5: Archivo con diferentes tamaños de buffer\n");

    #undef BUFFER_SIZE
    #define BUFFER_SIZE 1
    run_test("test_gnl/multiple_lines.txt");

    #undef BUFFER_SIZE
    #define BUFFER_SIZE 10
    run_test("test_gnl/multiple_lines.txt");

    #undef BUFFER_SIZE
    #define BUFFER_SIZE 100
    run_test("test_gnl/multiple_lines.txt");

    #undef BUFFER_SIZE
    #define BUFFER_SIZE 1000
    run_test("test_gnl/multiple_lines.txt");

    // Prueba 6: Archivo con líneas muy largas
    printf("\nPrueba 6: Archivo con líneas muy largas\n");
    #undef BUFFER_SIZE
    #define BUFFER_SIZE 42 // Restaurar el valor original
    run_test("test_gnl/long_lines.txt");

    // Prueba 7: Manejo de errores
    printf("\nPrueba 7: Manejo de errores\n");
    printf("Prueba 7.1: Descriptor de archivo inválido\n");
    char *line = get_next_line(-1);
    if (line == NULL) {
        printf("Manejo de descriptor de archivo inválido correcto\n");
    } else {
        printf("Error: Se esperaba NULL para un descriptor de archivo inválido\n");
        free(line);
    }

    printf("Prueba 7.2: Tamaño de buffer inválido\n");
    #undef BUFFER_SIZE
    #define BUFFER_SIZE 0
    line = get_next_line(open("test_gnl/multiple_lines.txt", O_RDONLY));
    if (line == NULL) {
        printf("Manejo de tamaño de buffer inválido correcto\n");
    } else {
        printf("Error: Se esperaba NULL para un tamaño de buffer inválido\n");
        free(line);
    }

    // Prueba 8: Archivo binario
    printf("\nPrueba 8: Archivo binario\n");
    #undef BUFFER_SIZE
    #define BUFFER_SIZE 42 // Restaurar el valor original
    run_test("test_gnl/binary_file.bin");

    // Prueba 9: Archivo con diferentes combinaciones de saltos de línea
    printf("\nPrueba 9: Archivo con diferentes combinaciones de saltos de línea\n");
    run_test("test_gnl/mixed_newlines.txt");

    // Prueba 10: Archivo grande
    printf("\nPrueba 10: Archivo grande\n");
    run_test("test_gnl/large_file.txt");

    return 0;
}