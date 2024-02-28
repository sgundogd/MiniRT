NAME	=	MiniRT
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
LIBFT	=	lib/libft/libft.a
MLX		=	lib/mlx/libmlx.a
GNL		=	lib/gnl

SRC_DIR	=	src
SRCS	=	$(SRC_DIR)/intersections.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/parse/utils.c \
			$(SRC_DIR)/parse/parser.c \
			$(SRC_DIR)/parse/init_cy.c \
			$(SRC_DIR)/parse/init_elements.c \
			$(SRC_DIR)/parse/init_pl.c\
			$(SRC_DIR)/parse/init_sp.c \
			$(SRC_DIR)/parse/init_objects.c \
			$(SRC_DIR)/parse/get_next_line.c \
			$(SRC_DIR)/parse/get_next_line_utils.c \
			$(SRC_DIR)/test_mlx.c \
			$(SRC_DIR)/test.c \
			$(SRC_DIR)/vector.c \

OBJ_DIR	=	obj
OBJS	=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:$(MLX) $(NAME)

$(NAME):$(MLX) $(OBJ_DIR) $(OBJS)
	@make -C lib/libft
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -L./lib/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "****   minirt ok!    ****"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parse

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(MLX):
#	make -C lib/mlx/
#$(LIBFT):
#	make -C lib/libft/

clean:
#	make clean -C lib/mlx/
	make clean -C lib/libft/
	${RM} $(OBJ_DIR)

fclean: clean
	${RM} ${NAME}
#	${RM} $(MLX)
	${RM} $(LIBFT)

re:			fclean all

.PHONY: all clean fclean re
