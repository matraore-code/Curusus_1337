/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:22:41 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 13:20:16 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void				ft_putunlong(unsigned int n)
{
	unsigned int nbr;
	unsigned int mod;

	nbr = n;
	mod = 0;
	if (n < 10)
		ft_putchar_fd(n + 48);
	else
	{
		mod = nbr % 10;
		nbr = nbr / 10;
		ft_putunlong(nbr);
		ft_putchar_fd((mod + 48));
	}
}

static int			get_lengt(unsigned int num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static t_tab		*do_u(t_tab *tab, unsigned int num, int num_width, int l)
{
	int			not_blank;

	not_blank = num_width;
	if (num_width <= tab->precision)
		not_blank = tab->precision;
	tab->len += (not_blank <= tab->width) ? tab->width : not_blank;
	if (!l)
		get_display(tab, ' ', tab->width - not_blank, 0);
	get_display(tab, '0', tab->precision - num_width, 0);
	ft_putunlong(num);
	if (l)
		get_display(tab, ' ', tab->width - not_blank, 0);
	return (tab);
}

t_tab				*d_unsigned(t_tab *tab)
{
	unsigned int	num;
	int				num_width;
	int				left;

	left = 0;
	num = (va_arg(tab->args, unsigned int));
	if (num == 0 && tab->precision == 0)
	{
		get_display(tab, ' ', tab->width, 1);
		return (tab);
	}
	num_width = get_lengt(num);
	if (tab->flags[0] == '-')
		left = 1;
	if (tab->flags[1] == '0' && tab->precision == -1 && !tab->flags[0])
		tab->precision = tab->width;
	do_u(tab, num, num_width, left);
	return (tab);
}
