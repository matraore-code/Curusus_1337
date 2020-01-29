/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 02:47:30 by matraore          #+#    #+#             */
/*   Updated: 2020/01/08 02:47:33 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int		traitement(t_tab *tab)
{
	tab->i++;
	flags(tab);
	width(tab);
	flags(tab);
	precision(tab);
	specifier(tab);
	d_switch(tab);
	return (tab->len);
}
