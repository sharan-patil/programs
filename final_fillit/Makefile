FLAGS = -Wall -Wextra -Werror -I libft -o fillit

FILES = fillit.c functionsfillit.c iterativeimp.c libft/libft.a

NAME = fillit

$(NAME): $(FILES)
	gcc $(FLAGS) $(FILES)

$(FILES):
	make -C libft

all: $(NAME)

clean:
	rm -rf libft/*.o

fclean: clean
	rm -rf fillit
	rm -rf libft/libft.a

re: fclean all
