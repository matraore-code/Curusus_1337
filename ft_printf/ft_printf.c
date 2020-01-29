/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 23:55:50 by matraore          #+#    #+#             */
/*   Updated: 2020/01/13 14:22:07 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_tab *tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	tab = initialize(tab);
	if (format)
	{
		va_start(tab->args, format);
		tab->len = parser(tab);
		va_end(tab->args);
	}
	free(tab);
	return (tab->len);
}
