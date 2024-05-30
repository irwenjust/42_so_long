/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:18:19 by likong            #+#    #+#             */
/*   Updated: 2024/05/28 14:29:18 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		add;
	int		perc;
	int		len;
	int		slen;
	int		mlen;
	int		tlen;
	int		dot;
	int		neg;
	int		nul;
	int		err;
	char	*base;
}	t_flags;

typedef struct s_data
{
	int		i;
	char	*str;
	va_list	ap;
}	t_data;

# define CONVERSIONS "%cspdiuxX\0"
# define MNUMBER "0123456789*"

# define DECIMEL "0123456789"
# define HEXL "0123456789abcdef"
# define HEXH "0123456789ABCDEF"

//tool functions
char	*ft_strchr(char *s, int c);
int		ft_atoi(const char *str);
size_t	str_length(char *str);
int		count_num_len(int num);
int		put_char(char c, t_flags *fg);
int		get_number_size(uintptr_t num, int base_size);
int		print_number_base(uintptr_t num, char *base, t_flags *fg);
int		print_base_h(uintptr_t nbr, t_flags *fg, char **buff, int *index);
void	check_buffer(char *buff, int *index, char c, t_flags *fg);

//two struct functions
t_flags	check_flags(char *str, size_t *i, va_list elements);

//mainly functions for bonus
int		ft_printf(const char *str, ...);
int		ft_putnbr_bonus(int n, t_flags *fg);
int		ft_putchar_bonus(int c, t_flags *fg);
int		ft_putstr_bonus(char *str, t_flags *fg);
int		ft_putpoint_bonus(void *str, t_flags *fg);
int		ft_putunbr_bonus(unsigned int num, t_flags *fg);
int		ft_puthex_bonus(unsigned int unum, char *str, t_flags *fg);

#endif
