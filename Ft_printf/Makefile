# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stabares <stabares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 21:17:08 by stabares          #+#    #+#              #
#    Updated: 2025/02/13 15:29:16 by stabares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ·Compilador y flags
CC = gcc
FLAG = -Wall -Werror -Wextra

# ·Archivos fuente y objetos
SRC = ft_printf.c ft_print_content.c ft_utils.c
OBJ = $(SRC:.c=.o)

# ·Nombre de la biblioteca
NAME = libftprintf.a

# ·Incluir el archivo de cabecera
INCLUDE = ft_printf.h

# Regla principal: compila la librería ft_printf
all: $(NAME)

# Regla para crear la biblioteca $(NAME) con los objetos $(OBJ)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Regla para compilar los archivos fuente .c en objetos .o
%.o: %.c $(INCLUDE)
	$(CC) $(FLAG) -c $< -o $@

# Limpiar archivos objeto
clean:
	@rm -f $(OBJ)

# Limpieza completa
fclean: clean
	@rm -f $(NAME)

# Reconstruir todo
re: fclean all

.PHONY: all clean fclean re