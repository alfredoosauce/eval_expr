NAME: eval_expr
FILES: main.c case.c eval_expr.c helperfuncs.c stackfuncs.c

.PHONY: all clean fclean re

all:
	gcc -Wall -Werror -Wextra -o $(NAME) $(FILES)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
