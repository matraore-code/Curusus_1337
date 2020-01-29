/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:47:16 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:32:55 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_tab		*d_switch(t_tab *tab)
{
	char	*flag;

	flag = &tab->specifier_flag;
	if (*flag == 'c')
		d_c(tab);
	if (*flag == '%')
		d_percent(tab);
	if (*flag == 's')
		d_s(tab);
	if (*flag == 'x')
		d_x(tab);
	if (*flag == 'X')
		d_xmax(tab);
	if (*flag == 'd' || *flag == 'i')
		d_d(tab);
	if (*flag == 'u')
		d_unsigned(tab);
	if (*flag == 'p')
		d_pvoid(tab);
	return (tab);
}
