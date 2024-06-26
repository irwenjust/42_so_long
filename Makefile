NAME = so_long
NAMEBONUS = so_long_bonus
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX = ./MLX42

HEADERS = -I ./include -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS = $(shell find ./src -iname "*.c")
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = $(shell find ./bonus -iname "*.c")
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = -L./libft -lft

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

bonus: libmlx $(NAMEBONUS)

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
