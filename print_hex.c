/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:02:33 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 01:02:51 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_hex(t_properties *props, unsigned int hex, char c)
{
	char	*str;

	if (props->precision == 0 && hex != 0)
		props->precision = -1;
	if ((str = itoa_base(hex, 16, c)) == NULL)
		return (-1);
	print_all_nums(str, props, props->precision, ft_strlen(str));
	return (0);
}
