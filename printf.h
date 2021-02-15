/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:44:06 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 00:51:40 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>

# define FLAG_MINUS 0b00000010
# define FLAG_ZERO  0b00000100

# define ALL_SYMBOLS "0123456789abcdef"

typedef struct	s_properties
{
	int	flags;
	int	width;
	int	precision;
	int	length;
}				t_properties;

int				ft_printf(const char *format, ...);
int				ft_strlen(const char *str);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				print_pointer(t_properties *props, uintptr_t ptr);
int				print_hex(t_properties *props, unsigned int hex, char c);
int				print_uint(t_properties *props, unsigned int uint);
int				print_int(t_properties *props, int num);
int				parse(va_list *ap, t_properties *props, const char **format);
char			*itoa_base(long long int num, int base, char c);
void			print_string(t_properties *props, char *str);
void			print_char(t_properties *props, int c);
void			print_all_nums(char *str, t_properties *props, int precision,
								int len);

#endif
