/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:03:30 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 01:04:55 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_minus(char *str, t_properties *props, int precision, int len)
{
	int	width;

	width = props->width;
	while (props->precision-- > len)
		props->length += ft_putchar('0');
	while (*str != '\0')
		props->length += ft_putchar(*str++);
	while ((precision >= len && width-- > precision) ||
				(len > precision && width-- > len))
		props->length += ft_putchar(props->flags & FLAG_ZERO ? '0' : ' ');
	free(str - len);
}

void		print_all_nums(char *str, t_properties *props, int precision,
							int len)
{
	int	width;

	width = props->width;
	if (precision == 0)
	{
		free(str);
		while (width--)
			props->length += ft_putchar(props->flags & FLAG_ZERO ? '0' : ' ');
		return ;
	}
	if (props->flags & FLAG_MINUS)
	{
		print_minus(str, props, precision, len);
		return ;
	}
	while ((precision >= len && width-- > precision) ||
			(len > precision && width-- > len))
		props->length += ft_putchar(props->flags & FLAG_ZERO ? '0' : ' ');
	while (precision-- > len)
		props->length += ft_putchar('0');
	while (*str != '\0')
		props->length += ft_putchar(*str++);
	free(str - len);
}
