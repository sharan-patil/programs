FLAGS = -Wall -Wextra -Werror -I libft -o fillit

FILES = fillit.c functionsFillit.c libft/libft.a

NAME = fillit

$(NAME):
	make -C libft
	gcc $(FLAGS) $(FILES)

all: $(NAME)

clean:
	rm -rf libft/*.o

fclean: clean
	rm -rf fillit
	rm -rf libft/libft.a

re: fclean all
