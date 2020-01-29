/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:44:57 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:09:42 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*initialize(t_tab *tab)
{
	tab->len = 0;
	tab->i = 0;
	tab->specifier_mask = "scdiuxXp%";
	tab->flags_mask = "-0*";
	tab->f_treat = (char *)tab->format;
	tab->f_copy = (char *)tab->format;
	return (tab);
}

t_tab	*reinitialize(t_tab *tab)
{
	tab->specifier_flag = '\0';
	tab->flags[0] = '\0';
	tab->flags[1] = '\0';
	tab->flags[2] = '\0';
	tab->flags[3] = '\0';
	tab->precision = -1;
	tab->point_trouve = 0;
	tab->width = 0;
	tab->j = 0;
	tab->k = 0;
	return (tab);
}
