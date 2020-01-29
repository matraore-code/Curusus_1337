/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:19:52 by matraore          #+#    #+#             */
/*   Updated: 2020/01/13 13:51:58 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_tab			*d_s(t_tab *tab)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(tab->args, char *);
	if (tab->precision > -1 && s)
		s = ft_strlcpy(s, tab->precision);
	else if (tab->precision == -1 && s)
		s = ft_strdup(s);
	else if (tab->precision > -1 && !s)
		s = ft_strlcpy("(null)", tab->precision);
	else if (tab->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	tab->len += len;
	if (tab->flags[0] != '-' && tab->width > len)
		get_display(tab, ' ', tab->width - len, 1);
	ft_putstr_fd(s);
	if (tab->flags[0] == '-')
		get_display(tab, ' ', tab->width - len, 1);
	free(s);
	return (tab);
}
