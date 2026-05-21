/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:38:06 by gerramir          #+#    #+#             */
/*   Updated: 2026/05/06 22:50:20 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(char c)
{
	return (c == 'd' || c == 's' || c == 'p' || c == 'c' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	ft_parsing(const char *format, va_list ap)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_valid(format[i + 1]))
		{
			count = count + find_arg(format[i + 1], ap);
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
			i++;
		}
	}
	return (count);
}
