NAME	=		libftprintf.a

CC		=		gcc

CFLAGS	=		-Wall -Wextra -Werror

SRC 	=		print_all_nums.c	print_char.c	print_int.c		print_hex.c		parser.c	\
				print_pointer.c		print_string.c	print_uint.c	printf.c		printf_utils.c

OBJ		=		$(SRC:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	@ranlib $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
