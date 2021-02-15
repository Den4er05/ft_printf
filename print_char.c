/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:03:07 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 01:03:13 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char(t_properties *props, int c)
{
	int width;

	width = --props->width;
	if (props->flags & FLAG_MINUS)
	{
		props->length += ft_putchar(c);
		while (width-- > 0)
			props->length += ft_putchar(props->flags & FLAG_ZERO ? '0' : ' ');
		return ;
	}
	while (width-- > 0)
		props->length += ft_putchar(props->flags & FLAG_ZERO ? '0' : ' ');
	props->length += ft_putchar(c);
}
