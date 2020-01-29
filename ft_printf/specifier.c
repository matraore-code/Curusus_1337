/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:46:30 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:29:21 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*specifier(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->specifier_mask[i] != '\0')
	{
		if (tab->specifier_mask[i] == tab->f_treat[tab->i])
			tab->specifier_flag = tab->specifier_mask[i];
		i++;
	}
	return (tab);
}
