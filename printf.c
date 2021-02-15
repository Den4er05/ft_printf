/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:52:08 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 00:53:15 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	nullstruct(t_properties *props)
{
	props->flags = 0;
	props->width = 0;
	props->precision = -1;
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	t_properties	props;
	int				tmp;

	va_start(ap, format);
	nullstruct(&props);
	props.length = 0;
	while (*format != '\0')
	{
		if (*format != '%')
			props.length += ft_putchar(*format);
		else
		{
			nullstruct(&props);
			if ((tmp = parse(&ap, &props, &format)) == -1)
				return (-1);
		}
		if (*format == '\0')
			break ;
		++format;
	}
	va_end(ap);
	return (props.length);
}
