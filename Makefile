

NAME = so_long
HEADER = header/libsolong.h

LIBFT = libft/libft.a
LIBFT_H = libft/libft.h

MLX = minilibx-linux/libmlx.a

COMPILE = cc -Wall -Wextra -Werror

SRC_PATH = src/
OBJ_PATH = obj/

SRC = main.c
SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix obj/, $(OBJ))

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -c $^ -o $@

$(LIBFT):
	make -C libft -s

$(MLX):
	make -C minilibx-linux -s

$(NAME): $(OBJS) $(HEADER)
	$(COMPILE) $(OBJS) $(LIBFT) $(MLX) -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re