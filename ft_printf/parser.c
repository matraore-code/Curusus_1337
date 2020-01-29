/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:46:45 by matraore          #+#    #+#             */
/*   Updated: 2020/01/20 10:23:43 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int	parser(t_tab *tab)
{
	while (tab->f_copy[tab->i] != '\0')
	{
		if (tab->f_copy[tab->i] == '%')
		{
			reinitialize(tab);
			traitement(tab);
		}
		else
		{
			write(1, &tab->f_copy[tab->i], 1);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}
