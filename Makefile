NAME := so_long
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast -I/Users/likong/.brew/opt/glfw/include
LIBMLX := ./MLX42

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a -L/Users/likong/.brew/opt/glfw/lib -lglfw -pthread -lm
SRCS := $(shell find ./src -iname "*.c")
OBJS := $(SRCS:.c=.o)

LIBFT = -L./libft -lft

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C ./libft fclean

re: clean all

.PHONY: all clean fclean re libmlx
