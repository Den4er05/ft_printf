/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:55:18 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 00:56:24 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_uint(t_properties *props, unsigned int uint)
{
	char	*str;

	if (props->precision == 0 && uint != 0)
		props->precision = -1;
	if ((str = itoa_base(uint, 10, 'u')) == NULL)
		return (-1);
	print_all_nums(str, props, props->precision, ft_strlen(str));
	return (0);
}
