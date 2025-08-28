

NAME		=	so_long
HEADER		=	libsolong.h

LIBFT_PATH	=	./libraries/libft/
LIBFT		=	$(LIBFT_PATH)libft.a
LIBFT_H		=	$(LIBFT_PATH)libft.h

# MLX_PATH	=	./libraries/minilibx-linux/
# MLX			=	./libraries/minilibx-linux/libmlx.a

COMPILE 	=	cc -Wall -Wextra -Werror

SRC_DIR 	=	./src/
OBJ_DIR 	=	./obj/

SRC			=	main.c\
				ft_handle_input.c\
				ft_init_game.c\
				ft_init_sprites.c\
				ft_init_map.c\
				ft_parse_map.c\
				ft_render_map.c\
				ft_validate_args.c\
				ft_frees.c\
				ft_err_msg_exit.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC))

OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))

all:	$(OBJ_DIR) $(LIBFT) $(NAME) #$(MLX)

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		$(COMPILE) -c $^ -o $@

$(LIBFT):
		make -C $(LIBFT_PATH) -s

# $(MLX):
# 		make -C $(MLX_PATH) -s

$(NAME):$(OBJS) $(HEADER)
		$(COMPILE) $(OBJS) $(LIBFT) -B libraries/minilibx-linux -lmlx -lXext -lX11 -o $(NAME)
#-L/usr/lib -Iminilibx_linux -lz  -lm -Lminilibx_linux

vlgr: all
		touch mlx.supp
		printf '{\n   x11_writev\n   Memcheck:Param\n   writev(vector[0])\n   fun:writev\n}\n' > mlx.supp
		valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=mlx.supp ./so_long ./maps/valid/1valid.ber
		rm -rf mlx.supp

clean:
		make clean -C $(LIBFT_PATH) -s
# 		make clean -C $(MLX_PATH) -s
		rm -rf $(OBJ_DIR)

fclean:
		make fclean -C $(LIBFT_PATH) -s
# 		make clean -C $(MLX_PATH) -s
		rm -rf $(OBJ_DIR)
		rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re