/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:37:06 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 09:51:26 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		get_length(long num)
{
	int tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

static char		negativity(int is_negative)
{
	if (is_negative)
		return ('-');
	return ('\0');
}

static t_tab	*do_l(t_tab *tab, long num, int num_width, char negatvity)
{
	if ((num == 0 && tab->flags[1] == '0') || tab->j)
	{
		get_display(tab, ' ', tab->precision - num_width, 0);
		if (negatvity && tab->j)
			ft_putchar_fd('-');
	}
	else
	{
		get_display(tab, '0', tab->precision - num_width, 0);
	}
	return (tab);
}

static t_tab	*do_d(t_tab *tab, long num, int num_width, int align_left)
{
	int			not_blank;
	char		negatvity_placeholder;
	int			is_negative;

	is_negative = (num < 0) ? 1 : 0;
	num *= (is_negative) ? -1 : 1;
	negatvity_placeholder = negativity(is_negative);
	not_blank = num_width;
	if (num_width <= tab->precision && tab->precision >= 0)
		not_blank = tab->precision;
	if (negatvity_placeholder)
		not_blank++;
	tab->len += (not_blank <= tab->width) ? tab->width : not_blank;
	if (!align_left && tab->width > not_blank && tab->flags[1] != '0')
		get_display(tab, ' ', tab->width - not_blank, 0);
	if (negatvity_placeholder && tab->j == 0)
		write(1, &negatvity_placeholder, 1);
	if (!align_left && tab->flags[1] && tab->precision == -1)
		get_display(tab, '0', tab->width - not_blank, 0);
	do_l(tab, num, num_width, negatvity_placeholder);
	((tab->j == 1 && num == 0) || (tab->k == 1 && num == 0)) ?
		0 : ft_putnbr(num);
	if (align_left)
		get_display(tab, ' ', tab->width - not_blank, 0);
	return (tab);
}

t_tab			*d_d(t_tab *tab)
{
	long		num;
	int			num_width;
	int			align_left;

	num = (va_arg(tab->args, int));
	num_width = (num == 0 && tab->precision == 0) ? 0 : get_length(num);
	align_left = (tab->flags[0] == '-') ? 1 : 0;
	if (tab->flags[1] == '0' && tab->precision == 0)
	{
		tab->precision = tab->width;
		if (num < 0 || tab->flags[2] || tab->flags[0])
			tab->precision--;
	}
	if (tab->flags[1] == '0' && tab->precision > 0)
		tab->flags[1] = '\0';
	do_d(tab, num, num_width, align_left);
	return (tab);
}
