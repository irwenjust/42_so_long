NAME = so_long
NAMEBONUS = so_long_bonus
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX = ./MLX42

HEADERS = -I ./include -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS =	src/create_map.c src/delete.c src/draw.c src/hook.c src/init.c \
		src/main.c src/move_player.c src/tools.c src/validate_map.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS =	bonus/create_map_bonus.c bonus/delete_bonus.c bonus/draw_bonus.c \
				bonus/hook_bonus.c bonus/init_bonus.c bonus/main_bonus.c \
				bonus/move_player_bonus.c bonus/pixel_bonus.c bonus/tools_bonus.c \
				bonus/update_bonus.c bonus/validate_map_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = -L./libft -lft

# MLX42

REPO_URL=https://github.com/codam-coding-college/MLX42.git
REPO_DIR=MLX42

all: clone libmlx $(NAME)

clone:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		git clone $(REPO_URL); \
	else \
		echo "$(REPO_DIR) already exists."; \
	fi

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

bonus: clone libmlx $(NAMEBONUS)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME) -Ofast

$(NAMEBONUS): $(BONUS_OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(BONUS_OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAMEBONUS) -Ofast

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -rf $(NAME) $(NAMEBONUS)
	@$(MAKE) -C ./libft fclean

re: clean all

.PHONY: all clean fclean re libmlx
