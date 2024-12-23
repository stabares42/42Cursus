# Compilador y flags
CC = gcc
FLAG = -Werror -Wall -Wextra

# Archivos fuente y objetos
SRC = ft_printf.c utils.c
OBJ = $(SRC:.c=.o)

# Nombre de la biblioteca
NAME = libftprintf.a

# Librería libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#
$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ)                # Crea la biblioteca $(NAME) con los objetos $(OBJ)
	ar x $(LIBFT)                        # Extrae los objetos de $(LIBFT)
	ar rcs $(NAME) *.o                   # Añade los objetos extraídos a $(NAME)
	rm -f *.o  


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

# Regla principal
all: $(LIBFT) $(NAME) copy_libft

bonus: $(LIBFT) $(NAME)

# Limpiar archivos objeto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Limpieza completa
fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	$(MAKE) -C $(LIBFT_DIR) fclean

# Reconstruir todo
re: fclean all

copy_libft: 
	cp $(LIBFT) .
