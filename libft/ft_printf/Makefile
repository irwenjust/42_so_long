CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rcs

TARGET =	ft_printf.o ft_printf_tool.o ft_putchar.o ft_putstr.o ft_putpoint.o \
			ft_putnbr.o ft_putnum_unsign.o ft_puthex.o

BONUS_TARGET =	bonus/ft_atoi.o bonus/ft_flags.o bonus/ft_printf_bonus.o \
				bonus/ft_printf_tool_bonus.o bonus/ft_putnbr_bonus.o \
				bonus/ft_putchar_bonus.o bonus/ft_putstr_bonus.o \
				bonus/ft_putpoint_bonus.o bonus/ft_putunbr_bonus.o bonus/ft_puthex_bonus.o \
				bonus/ft_printf_tool2_bonus.o

NAME = libftprintf.a

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: .bonus

.bonus: $(BONUS_TARGET)
	$(AR) $(NAME) $^
	@touch .bonus

$(NAME): $(TARGET)
	$(AR) $(NAME) $^

clean:
	$(RM) $(TARGET) $(BONUS_TARGET)
	@rm -f .bonus

fclean: clean
	$(RM) $(NAME) $(BONUS_TARGET)

re: fclean all
