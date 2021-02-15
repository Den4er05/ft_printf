/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 01:00:14 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 01:02:15 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*add_nulls_and_copy(char *str, int null_count, int str_len,
									t_properties *props)
{
	int		str_counter;
	int		idx;
	char	*for_del;

	for_del = str;
	if (null_count < 1)
	{
		if ((str = malloc(str_len + 2)) == NULL)
			return (NULL);
	}
	else if ((str = malloc(str_len + 2 + null_count)) == NULL)
		return (NULL);
	str[0] = '-';
	str_counter = 1;
	while (null_count-- > 0 || (props->flags & FLAG_ZERO
									&& --props->width > str_len))
		str[str_counter++] = '0';
	idx = 0;
	while ((str[str_counter++] = for_del[idx++]) != '\0')
		;
	free(for_del);
	return (str);
}

int			print_int(t_properties *props, int num)
{
	int		len;
	int		precision;
	char	*str;

	if (props->precision == 0 && num != 0)
		props->precision = -1;
	if ((str = itoa_base(num, 10, 'd')) == NULL)
		return (-1);
	len = ft_strlen(str);
	precision = props->precision;
	if (num < 0)
		if ((str = add_nulls_and_copy(str, precision - len, len, props))
													== NULL)
			return (-1);
	print_all_nums(str, props, props->precision, ft_strlen(str));
	return (0);
}
