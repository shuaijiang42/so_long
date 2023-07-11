NAME = so_long

SOURCES = main.c check_map.c error_handling.c get_map.c print_map.c
# BONUS_SOURCES = 
		
OBJECTS = $(SOURCES:.c=.o)
# BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

LIB = libft/libft.a

CC = gcc
CFLAGS += -Wextra -Werror -Wall  -I ./libft -g3 -fsanitize=address
MLXFLGS = -Imlx -lmlx -framework OpenGL -framework AppKit
 
all: $(NAME) 

$(NAME): $(OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) $(MLXFLGS) -o $(NAME)


# bonus: $(BONUS_OBJECTS)
#	ar rcs $(NAME) $(BONUS_OBJECTS)

clean:
	make clean -C libft
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean:
	make fclean -C libft
	rm -f $(NAME) $(OBJECTS)

re: fclean all 
.SILENT: