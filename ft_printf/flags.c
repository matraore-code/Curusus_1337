/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:59:33 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:00:44 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*flags(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->flags_mask[i] != '\0')
	{
		while (tab->flags_mask[i] == tab->f_treat[tab->i])
		{
			while (tab->f_treat[tab->i] == '-' && tab->i++)
				tab->flags[0] = '-';
			while (tab->f_treat[tab->i] == '0' && tab->i++)
				tab->flags[1] = '0';
			while (tab->f_treat[tab->i] == '*' && tab->i++)
				tab->flags[2] = '*';
			i = 0;
		}
		i++;
	}
	return (tab);
}
