# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 15:23:49 by mtrullar          #+#    #+#              #
#    Updated: 2024/07/28 17:39:10 by mtrullar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME		=	so_long
NAME_BONUS  =	so_long_bonus
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror

#Folders
INCLUDE		=	incs/
INCLUDE_BONUS =	incs_bonus/
SRCS_BONUS_DIR = srcs_bonus/
SRCS_DIR	=	srcs/
LIBFT		=	libft/
MLX_DIR		=	mlx/
OBJ_DIR		=	obj/
OBJ_DIR_BONUS = obj_bonus/

RM			=	@rm -rf

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

BOLD_OPACITY = \e[1m
DEF_STYLE    = \e[0m


SRC_FILE =	init_game/create_game.c	\
		init_game/is_playable.c		\
		init_game/map_error.c		\
		init_game/parsing.c			\
		init_game/map_creation.c	\
		init_game/texture_status.c	\
		init_game/verif_ext.c		\
		init_game/free_func.c		\
		in_game/struct_func.c		\
		in_game/movements.c			\
		in_game/game_status.c		\
		render/render_map.c			\
		main.c						\

SRC_FILE_BONUS =	init_game/create_struct_bonus.c	\
		init_game/is_playable_bonus.c			\
		init_game/map_error_bonus.c				\
		init_game/parsing_bonus.c				\
		init_game/map_creation_bonus.c			\
		init_game/texture_status_bonus.c		\
		init_game/verif_ext_bonus.c				\
		init_game/free_func_bonus.c				\
		init_game/struct_tab_bonus.c			\
		in_game/struct_func_bonus.c				\
		in_game/movements_bonus.c				\
		in_game/game_status_bonus.c				\
		in_game/opps_movements_bonus.c			\
		render/render_map_bonus.c				\
		render/render_player_bonus.c			\
		render/render_moovs_bonus.c				\
		render/render_opps_bonus.c				\
		main_bonus.c							\

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILE))
OBJ  = $(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR), $(SRC_FILE_BONUS))
OBJ_BONUS  = $(addprefix $(OBJ_DIR_BONUS), $(SRC_FILE_BONUS:.c=.o))

OBJF = .cache_exists
OBJF_BONUS = .bonus_cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) -I$(INCLUDE) $(OBJ) -L$(LIBFT) -lcustomft -L$(MLX_DIR) -lmlx -lX11 -lXext
	@echo "$(GREEN)\e[1mSO_LONG COMPILED\e[0m $(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@
	@echo "$(MAGENTA)\e[1mSO_LONG compiling:\e[0m $< $(DEF_COLOR)"


$(OBJ_DIR_BONUS)%.o: $(SRCS_BONUS_DIR)%.c | $(OBJF_BONUS)
	@$(CC) $(CFLAGS) -I$(INCLUDE_BONUS) -c $< -o $@
	@echo "$(MAGENTA)\e[1mSO_LONG_BONUS compiling:\e[0m $< $(DEF_COLOR)"

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/init_game
	@mkdir -p $(OBJ_DIR)/in_game
	@mkdir -p $(OBJ_DIR)/render

$(OBJF_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)
	@mkdir -p $(OBJ_DIR_BONUS)/init_game
	@mkdir -p $(OBJ_DIR_BONUS)/in_game
	@mkdir -p $(OBJ_DIR_BONUS)/render


$(NAME_BONUS) : $(OBJ_BONUS)
	@make -sC $(MLX_DIR)
	@make -sC $(LIBFT)
	@$(CC) -o $(NAME_BONUS) $(CFLAGS) -I$(INCLUDE_BONUS) $(OBJ_BONUS) -L$(LIBFT) -lcustomft -L$(MLX_DIR) -lmlx -lX11 -lXext
	@echo "$(GREEN)\e[1mSO_LONG_BONUS COMPILED\e[0m $(DEF_COLOR)"

bonus: $(NAME_BONUS)

runtest: all
	@echo "$(GREEN) \n\n \e[1mTESTER FOR SO_LONG LEAKS\e[0m \n\n $(DEF_COLOR)$(DEF_STYLE)"
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Empty map --only \ n \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/empty_map_2.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Empty map \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/empty_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) False map -- unaccepted character \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/false_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map too wide \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/map_too_big_1.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map too long \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/map_too_big.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) .Txt map \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/map.txt
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map without collectible \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/no_collectible.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map without player \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/no_player.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map without exit \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/no_exit.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Not rectangular map \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/not_rect_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Open map --top is open \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/open_map_2.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Open map --left is open \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/open_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map with two exit \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/two_exit.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map with two player \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/two_player.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map with unreachable exit \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/unreachable_ex.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Map with unreachable collectible \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/unreachable_col.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Small map\n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/small_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG]$(MAGENTA) Classic map\n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/map.ber

runtestbonus: $(NAME_BONUS)
	@echo "$(GREEN) \n\n \e[1mTESTER FOR SO_LONG_BONUS LEAKS\e[0m \n\n $(DEF_COLOR)$(DEF_STYLE)"
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Empty map --only \ n \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/empty_map_2.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Empty map \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/empty_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) False map -- unaccepted character \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/false_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map too wide \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/map_too_big_1.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map too long \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/map_too_big.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) .Txt map \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/map.txt
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map without collectible \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/no_collectible.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map without player \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/no_player.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map without exit \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/no_exit.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Not rectangular map \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/not_rect_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Open map --top is open \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/open_map_2.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Open map --left is open \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/open_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map with two exit \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/two_exit.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map with two player \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/two_player.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map with unreachable exit \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/unreachable_ex.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Map with unreachable collectible \n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/unreachable_col.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Small map\n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/small_map.ber
	@echo "$(BOLD_OPACITY)\n[SO_LONG_BONUS]$(MAGENTA) Classic map\n$(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) map/map.ber
	
norm:
	norminette -R CheckForniddenHeader incs incs_bonus libft srcs srcs_bonus

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJ_DIR_BONUS)
	@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@make fclean -sC $(LIBFT)
	@make clean -sC $(MLX_DIR)
	@echo "$(CYAN)Executable destroyed!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)\e[1mSO_LONG has been rebuilt, fresh and clean\e[0m$(DEF_COLOR)"

rebonus: fclean bonus
	@echo "$(GREEN)\e[1mSO_LONG_BONUS has been rebuilt, fresh and clean\e[0m$(DEF_COLOR)"

.PHONY: all clean fclean re rebonus runtestbonus runtest norm


