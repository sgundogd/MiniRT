NAME = MiniRT
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCS = ./main.c ./utils.c ./parser.c ./utils_cy.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./utils_elements.c ./utils_pl.c ./utils_sp.c \

OBJ = $(SRCS:.c=.o)
RM = rm -rf
LIBFT = libft/libft.a
MLX = mlx/libmlx.a

all:$(MLX) $(NAME)

$(NAME):$(MLX) $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(OBJ) $(LIBFT)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "****   minirt ok!    ****"

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c  $< -o $@

$(MLX):
	make -C mlx/

$(LIBFT):
	make -C libft/

clean:
	make clean -C mlx/
	make clean -C libft/
	${RM} $(OBJ)

fclean: clean
	${RM} ${NAME}
	${RM} $(MLX)
	${RM} $(LIBFT)

re:			fclean all

.PHONY: all clean fclean re