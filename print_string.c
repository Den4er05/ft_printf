/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:56:36 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 00:59:03 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_string(t_properties *props, char *str)
{
	int	len;
	int	precision;
	int	width;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	precision = props->precision;
	width = props->width;
	if (props->flags & FLAG_MINUS)
	{
		while (*str != '\0' && props->precision--)
			props->length += ft_putchar(*str++);
		while ((precision > 0 && len > precision && width-- > precision) ||
				(precision == 0 && width-- > 0) || width-- > len)
			props->length += ft_putchar(props->flags & FLAG_ZERO ? '0' : ' ');
		return ;
	}
	while ((precision > 0 && len > precision && width-- > precision) ||
			(precision == 0 && width-- > 0) || width-- > len)
		props->length += ft_putchar(props->flags & FLAG_ZERO ? '0' : ' ');
	while (*str != '\0' && precision--)
		props->length += ft_putchar(*str++);
}
