/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:10:48 by tlemma            #+#    #+#             */
/*   Updated: 2021/10/26 10:48:21 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern size_t	g_count;

void	ft_putchar(unsigned char c)
{
	g_count += write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
		while (*s)
			ft_putchar(*s++);
	else
		ft_putstr("(null)");
}

void	ft_putnbr_base(long n, char *base, int size)
{
	long	mod;

	mod = 0;
	if (n < 0 && n)
	{
		ft_putchar('-');
		n = -1 * n;
	}
	if (n < size)
		ft_putchar(base[n]);
	if (n >= size)
	{
		mod = (n % size);
		n = n / size;
		ft_putnbr_base(n, base, size);
		ft_putchar(base[mod]);
	}
}

void	ft_putnbr_base_u(unsigned long n, char *base, unsigned int size)
{
	int	mod;

	mod = 0;
	if (n < size)
		ft_putchar(base[n]);
	if (n >= size)
	{
		mod = (n % size);
		n = n / size;
		ft_putnbr_base(n, base, size);
		ft_putchar(base[mod]);
	}
}
