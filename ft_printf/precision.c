/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:46:16 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:25:47 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	mul(t_tab *tab)
{
	while (tab->f_treat[tab->i] >= '0' && tab->f_treat[tab->i] <= '9')
	{
		tab->precision = tab->precision * 10 + (tab->f_treat[tab->i] - '0');
		tab->i++;
	}
	return (tab->precision);
}

t_tab		*precision(t_tab *tab)
{
	while (tab->f_treat[tab->i] == '.')
	{
		tab->i++;
		tab->precision = 0;
		tab->point_trouve = 1;
	}
	if (tab->point_trouve == 1)
	{
		if (tab->f_treat[tab->i] == '*')
		{
			tab->precision = va_arg(tab->args, int);
			(tab->precision < 0) ? tab->precision = -1 : tab->precision;
			tab->i++;
		}
		if (tab->f_treat[tab->i] >= '0' && tab->f_treat[tab->i] <= '9')
			mul(tab);
	}
	tab->j = (tab->precision == 0 && tab->flags[1] == '0') ? 1 : 0;
	tab->k = (tab->precision == 0 && tab->flags[1] != '0') ? 1 : 0;
	return (tab);
}
