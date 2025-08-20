

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

all: $(OBJ_PATH) $(LIBFT) $(MLX) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(COMPILE) -c $^ -o $@

$(LIBFT):
	make -C libft -s

$(MLX):
	make -C minilibx-linux -s

$(NAME): $(OBJS) $(HEADER)
	$(COMPILE) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -o $(NAME) 
#-L/usr/lib -Iminilibx_linux -lz  -lm -Lminilibx_linux
clean:
	make clean -C libft -s 
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libft -s
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re