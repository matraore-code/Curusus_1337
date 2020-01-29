/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:07:53 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:28:11 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	zerot(int j, t_tab *tab, int align_left)
{
	int c;

	c = 48;
	if (tab->flags[1] == '0' && !align_left)
	{
		while (j > 0)
		{
			write(1, &c, 1);
			j--;
			tab->len++;
		}
	}
	else if (!align_left && tab->flags[1] && tab->precision == -1)
	{
		while (tab->width - 1 > 0)
		{
			write(1, &c, 1);
			j--;
			tab->len++;
		}
	}
}

void	display_with_precisio(char s, t_tab *tab, int p)
{
	int j;
	int	align_left;

	j = tab->width - p;
	align_left = (tab->flags[0] == '-') ? 1 : 0;
	if (tab->flags[1] != '0' && !align_left && tab->width >= 1)
		get_display(tab, ' ', tab->width - 1, 1);
	zerot(j, tab, align_left);
	ft_putchar_fd(s);
	if (align_left)
		get_display(tab, ' ', tab->width - 1, 1);
	tab->len += 1;
}

void	pr_sp_e(t_tab *tab, int len)
{
	if (tab->flags[0] != '-' && tab->width > 1 && tab->flags[1] != '0')
		get_display(tab, ' ', tab->width - len, 1);
	if (tab->flags[1] == '0' && tab->width > 0)
		get_display(tab, '0', tab->width - len, 1);
}

t_tab	*d_percent(t_tab *tab)
{
	if (tab->precision > -1)
	{
		display_with_precisio('%', tab, 1);
		return (tab);
	}
	pr_sp_e(tab, 1);
	ft_putchar_fd('%');
	tab->len += 1;
	if (tab->flags[0] == '-')
		get_display(tab, ' ', tab->width - 1, 1);
	return (tab);
}
