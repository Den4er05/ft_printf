/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:53:27 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/26 00:55:03 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_toupper(int c)
{
	return (c >= 'a' && c <= 'z' ? (c - 'a' + 'A') : c);
}

int			ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int			ft_putstr(char *str)
{
	int len;

	len = 0;
	while (*str != '\0')
	{
		len += ft_putchar(*str);
		++str;
	}
	return (len);
}

int			ft_strlen(const char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
		++idx;
	return (idx);
}

char		*itoa_base(long long int num, int base, char c)
{
	long long int	copy;
	int				len;
	int				minus;
	char			*res;

	len = 1;
	copy = num;
	while ((copy /= base) != 0)
		++len;
	minus = (num < 0) ? -1 : 1;
	len += 2 * (c == 'p');
	if ((res = malloc(len + 1)) == NULL)
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (num % base > 9 && c == 'X')
			? ft_toupper(ALL_SYMBOLS[num % base])
			: ALL_SYMBOLS[(num % base) * minus];
		num /= base;
	}
	return (res);
}
