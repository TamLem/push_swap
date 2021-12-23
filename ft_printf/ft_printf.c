/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:12:43 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/26 10:51:59 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

size_t	g_count;

void
	print_formatted(char ft, va_list ap)
{
	if (ft == 'c')
		ft_putchar(va_arg(ap, int));
	if (ft == 's')
		ft_putstr(va_arg(ap, char *));
	if (ft == 'd' || ft == 'i')
		ft_putnbr_base(va_arg(ap, int), "0123456789", 10);
	if (ft == 'u')
		ft_putnbr_base_u(va_arg(ap, unsigned int), "0123456789", 10);
	if (ft == 'p')
		ft_putstr("0x");
	if (ft == 'p')
		ft_putnbr_base_u((unsigned long)va_arg(ap, void *),
			"0123456789abcdef", 16);
	if (ft == 'x')
		ft_putnbr_base_u(va_arg(ap, unsigned int), "0123456789abcdef", 16);
	if (ft == 'X')
		ft_putnbr_base_u(va_arg(ap, unsigned int), "0123456789ABCDEF", 16);
	if (ft == '%')
		ft_putchar(ft);
}

int
	ft_printf(const char *s, ...)
{
	va_list	ap;

	g_count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '\0')
				break ;
			print_formatted(*s, ap);
			s++;
		}
		if (*s != '\0' && *s != '%')
			ft_putchar(*s++);
	}
	va_end(ap);
	return (g_count);
}
