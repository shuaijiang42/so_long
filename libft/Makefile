NAME = libft.a
#ft_memcpy.c ft_strlen.c
SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
    ft_isprint.c  ft_memset.c ft_bzero.c \
     ft_memmove.c ft_strlcpy.c ft_strlcat.c \
    ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
    ft_strncmp.c ft_memchr.c  ft_strnstr.c \
    ft_atoi.c  ft_strdup.c ft_memcmp.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_calloc.c\
	get_next_line.c get_next_line_utils.c ft_printf_utils.c ft_printf.c 

BONUS_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c  \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c 
		
OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CFLAGS += -Wextra -Werror -Wall #-g3 -fsanitize=address
 
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# creat the static library ar: archive r: replace c: creat s: index; so this command creates or update

bonus: $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)  
fclean:
	rm -f $(NAME) $(OBJECTS)

re: fclean all 
