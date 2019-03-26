NAME		=	libftprintf.a

CFLAGS		=	-Wall -Werror -Wextra -I libft -c

FILES		=	ft_printf.c \
				libft/ft_atoi.c \
				libft/ft_putstr.c \
				libft/ft_strchr.c \
				libft/ft_strcpy.c \
				libft/ft_strdup.c \
				libft/ft_strlen.c \
				libft/ft_putchar.c \
				libft/ft_memalloc.c \
				libft/ft_bzero.c \
				libft/ft_strstr.c

OBJ			=	ft_printf.o \
				ft_atoi.o \
				ft_putstr.o \
				ft_strchr.o \
				ft_strcpy.o \
				ft_strdup.o \
				ft_strlen.o \
				ft_putchar.o \
				ft_memalloc.o \
				ft_bzero.o \
				ft_strstr.o

all: $(NAME)
	
$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

$(NAME): $(OBJ) ft_printf.h
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
 
re: clean all

.PHONY: clean fclean all re
