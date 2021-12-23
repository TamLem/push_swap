/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:09:41 by tlemma            #+#    #+#             */
/*   Updated: 2021/09/14 16:15:42 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(unsigned char c);
void	ft_putstr(char *s);
void	ft_putnbr_base(long n, char *base, int size);
void	ft_putnbr_base_u(unsigned long n, char *base, unsigned int size);

#endif
