/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:59:10 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 00:59:59 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_pointer(t_properties *props, uintptr_t ptr)
{
	char	*str;

	if ((str = itoa_base(ptr, 16, 'p')) == NULL)
		return (-1);
	str[0] = '0';
	str[1] = 'x';
	if (props->precision == 0)
	{
		props->precision = -1;
		str[2] = '\0';
	}
	print_all_nums(str, props, props->precision, ft_strlen(str));
	return (0);
}
