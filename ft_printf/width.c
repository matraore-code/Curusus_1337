/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:45:55 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:33:28 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*width(t_tab *tab)
{
	if (tab->flags[2] == '*')
	{
		tab->width = va_arg(tab->args, int);
		if (tab->width < 0)
		{
			tab->width *= -1;
			tab->flags[0] = '-';
			tab->flags[1] = '\0';
		}
		tab->flags[2] = '\0';
	}
	else
	{
		while (tab->f_treat[tab->i] >= '0' && tab->f_treat[tab->i] <= '9')
		{
			tab->width *= 10;
			tab->width += (tab->f_treat[tab->i] - 48);
			tab->i++;
		}
	}
	return (tab);
}
