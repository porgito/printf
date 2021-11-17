/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:26:03 by jlaurent          #+#    #+#             */
/*   Updated: 2021/11/15 21:01:35 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(t_print *tab, int a)
{
	unsigned int	j;

	a = va_arg(tab->args, int);
	if (a < 0)
	{
		tab->tl += ft_putchar('-');
		j = -a;
	}
	else
		j = a;
	if (j > 9)
	{
		ft_putnbr(tab, j / 10);
		j %= 10;
	}
	tab->tl += ft_putchar(j + '0');
}
