

LIBFT_PATH	=	./libraries/libft/
LIBFT		=	$(LIBFT_PATH)libft.a
COMPILE 	=	cc -Wall -Wextra -Werror

NAME		=	so_long
SRC_DIR 	=	./src/
OBJ_DIR 	=	./obj/
HEADER		=	$(SRC_DIR)libsolong.h
SRC			=	main.c\
				ft_validate_args.c\
				ft_init_map.c\
				ft_parse_map.c\
				ft_check_valid_path_to_win.c\
				ft_init_mlx.c\
				ft_init_sprites.c\
				ft_handle_input.c\
				ft_render_game.c\
				ft_frees.c\
				ft_err_msg_exit.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC))
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))


NAME_BONUS		=	bonus_so_long
SRC_DIR_BONUS	=	bonus_src/
OBJ_DIR_BONUS	=	bonus_obj/
HEADER_BONUS	=	$(SRC_DIR_BONUS)libsolong_bonus.h
SRC_BONUS		=	main_bonus.c\
					ft_validate_args_bonus.c\
					ft_init_map_bonus.c\
					ft_parse_map_bonus.c\
					ft_check_valid_path_to_win_bonus.c\
					ft_init_mlx_bonus.c\
					ft_init_sprites_bonus.c\
					ft_handle_input_bonus.c\
					ft_render_game_bonus.c\
					ft_frees_bonus.c\
					ft_err_msg_exit_bonus.c\
					ft_print_mvmnt_bonus.c
SRCS_BONUS		=	$(addprefix $(SRC_DIR_BONUS), $(SRC_BONUS))
OBJ_BONUS		=	$(SRC_BONUS:.c=.o)
OBJS_BONUS		=	$(addprefix $(OBJ_DIR_BONUS), $(OBJ_BONUS))

all:	$(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
		@$(COMPILE) -c $< -o $@

$(NAME):$(OBJS) $(HEADER)
		$(COMPILE) $(OBJS) $(LIBFT) -Llibraries/minilibx-linux -lmlx -lXext -lX11 -o $(NAME)

bonus:	$(OBJ_DIR_BONUS) $(LIBFT) $(NAME_BONUS)

$(OBJ_DIR_BONUS):
		@mkdir $(OBJ_DIR_BONUS)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c $(HEADER_BONUS)
		@$(COMPILE) -c $< -o $@

$(NAME_BONUS):$(OBJS_BONUS) $(HEADER_BONUS)
		$(COMPILE) $(OBJS_BONUS) $(LIBFT) -Llibraries/minilibx-linux -lmlx -lXext -lX11 -o $(NAME_BONUS)


$(LIBFT):
		make -C $(LIBFT_PATH) -s

MAP = ./maps/valid/ok10.ber
# Runs valgrind to check for memory leaks, uses suppression file to suppress known errors in minilibx
v: all
		valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP)

# Runs valgrind to check for memory leaks in the bonus version, uses suppression file to suppress known errors in minilibx
vb: bonus
		valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME_BONUS) $(MAP)

clean:
		@make clean -C $(LIBFT_PATH) -s
		@rm -rf $(OBJ_DIR)
		@rm -rf $(OBJ_DIR_BONUS)
		@echo "removed object files"

fclean:
		@make fclean -C $(LIBFT_PATH) -s
		@rm -rf $(OBJ_DIR)
		@rm -rf $(OBJ_DIR_BONUS)
		@rm -rf $(NAME)
		@rm -rf $(NAME_BONUS)
		@echo "removed object files and executables"

re:		fclean all

bonusre:	fclean bonus

.PHONY: all clean fclean re bonus vlgr bonusre