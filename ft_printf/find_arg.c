/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:36:58 by gerramir          #+#    #+#             */
/*   Updated: 2026/05/06 22:50:30 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(void)
{
	write(1, "%%", 1);
	return (1);
}

int	find_arg(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putnbr_adress(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putnbr_base_unsigned(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_hex(va_arg(ap, unsigned), c));
	else if (c == '%')
		return (ft_print());
	return (0);
}
