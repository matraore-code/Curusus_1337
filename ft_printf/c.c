/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:53:22 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 09:24:49 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_tab			*d_c(t_tab *tab)
{
	char		c;
	int			i;

	i = 0;
	c = va_arg(tab->args, int);
	tab->len = tab->len + 1;
	if (tab->flags[0] != '-')
		get_display(tab, ' ', tab->width - 1, 1);
	write(1, &c, 1);
	if (tab->flags[0] == '-')
		get_display(tab, ' ', tab->width - 1, 1);
	return (tab);
}
