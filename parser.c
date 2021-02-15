/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:05:03 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 01:07:31 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	parse_flags(const char **str, t_properties *props)
{
	++*str;
	while (**str != '\0')
	{
		if (**str == '0')
			props->flags |= FLAG_ZERO;
		else if (**str == '-')
			props->flags |= FLAG_MINUS;
		else
			break ;
		++*str;
	}
	if ((props->flags & FLAG_MINUS) != 0)
		props->flags = FLAG_MINUS;
}

static void	parse_width(const char **str, va_list *ap, t_properties *props)
{
	while (**str != '\0')
	{
		if (**str == '*')
		{
			props->width = va_arg(*ap, int);
			if (props->width < 0)
			{
				props->flags = FLAG_MINUS;
				props->width *= -1;
			}
		}
		else if (**str >= '0' && **str <= '9')
			props->width = props->width * 10 + (**str - '0');
		else
			break ;
		++*str;
	}
}

static void	parse_precision(const char **str, va_list *ap, t_properties *props)
{
	if (**str != '\0' && **str == '.')
	{
		++*str;
		props->precision = 0;
		if (**str == '*')
		{
			props->precision = va_arg(*ap, int);
			if (props->precision < 0)
				props->precision = -1;
			++*str;
		}
		while (**str >= '0' && **str <= '9')
		{
			props->precision = props->precision * 10 + (**str - '0');
			++*str;
		}
		if (props->precision > -1)
			props->flags &= ~FLAG_ZERO;
	}
}

static int	parse_type(const char **str, va_list *ap, t_properties *props)
{
	if (**str == '\0')
		return (0);
	if (**str == 'd' || **str == 'i')
		return (print_int(props, va_arg(*ap, int)));
	else if (**str == 'c')
		print_char(props, va_arg(*ap, int));
	else if (**str == 's')
		print_string(props, va_arg(*ap, char *));
	else if (**str == 'p')
		return (print_pointer(props, va_arg(*ap, uintptr_t)));
	else if (**str == 'u')
		return (print_uint(props, va_arg(*ap, unsigned int)));
	else if (**str == 'x')
		return (print_hex(props, va_arg(*ap, unsigned int), 'x'));
	else if (**str == 'X')
		return (print_hex(props, va_arg(*ap, unsigned int), 'X'));
	else if (**str == '%')
		print_char(props, '%');
	return (0);
}

int			parse(va_list *ap, t_properties *props, const char **format)
{
	parse_flags(format, props);
	parse_width(format, ap, props);
	parse_precision(format, ap, props);
	return (parse_type(format, ap, props));
}
