NAME = so_long
NAME_BONUS = so_long_bonus

SRC_DIR = ./src/
SRC_B_DIR = ./src_bonus/
SOURCES = main.c check_map.c error_handling.c get_map.c \
		movements.c flood_fill.c free.c
BONUS_SOURCES = bonus_main.c bonus_check_map.c bonus_error_handling.c bonus_get_map.c \
		bonus_movements.c bonus_flood_fill.c bonus_free.c bonus_put_player.c\
		bonus_check_map_utiles.c
		
OBJECTS = $(addprefix $(SRC_DIR), $(SOURCES:.c=.o))
BONUS_OBJECTS = $(addprefix $(SRC_B_DIR), $(BONUS_SOURCES:.c=.o))

LIB = libft/libft.a

CC = gcc
CFLAGS += -Wextra -Werror -Wall  -I ./libft
MLXFLGS = -Imlx -lmlx -framework OpenGL -framework AppKit
 
all: $(NAME) 
bonus: $(NAME_BONUS)
$(NAME): $(OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB) $(MLXFLGS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIB) $(MLXFLGS) -o $(NAME_BONUS)

clean:
	make clean -C libft
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean:
	make fclean -C libft
	rm -f $(NAME) $(OBJECTS) $(NAME_BONUS) $(BONUS_OBJECTS)

re: fclean all 
re_bonus:  fclean bonus
.SILENT: