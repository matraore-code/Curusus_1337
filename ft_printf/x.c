/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 03:22:52 by matraore          #+#    #+#             */
/*   Updated: 2020/01/13 22:07:29 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	zero(int j, t_tab *tab, int align_left, char *str)
{
	int c;

	c = 48;
	if (tab->precision > -1)
	{
		while (j > 0)
		{
			write(1, &c, 1);
			j--;
			tab->len++;
		}
	}
	else if (!align_left && tab->flags[1] && tab->precision == -1)
	{
		while ((tab->width - ft_strlen(str)) > 0)
		{
			write(1, &c, 1);
			j--;
			tab->len++;
		}
	}
}

char	*display_with_precision(char *s, t_tab *tab, int p)
{
	int j;
	int c;
	int k;
	int	align_left;

	j = tab->precision - p;
	c = ft_strlen(s);
	align_left = (tab->flags[0] == '-') ? 1 : 0;
	k = (tab->precision < (long)ft_strlen(s)) ? ft_strlen(s) : tab->precision;
	if (!align_left && tab->precision >= 0)
		get_display(tab, ' ', tab->width - k, 1);
	zero(j, tab, align_left, s);
	if (tab->width > 0)
		(tab->precision == 0 && *s == '0') ?
		ft_putchar_fd(' ') : ft_putstr_fd(s);
	else
		(tab->precision == 0 && *s == '0') ? 0 : ft_putstr_fd(s);
	if (align_left)
		get_display(tab, ' ', tab->width - k, 1);
	tab->len += (*s == '0' && tab->width == 0 && tab->precision <= 0) ? 0 : c;
	return (s);
}

void	pr_sp(t_tab *tab, int len)
{
	if (tab->flags[0] != '-' && tab->width > 0 && !tab->flags[1])
		get_display(tab, ' ', tab->width - len, 1);
	if (tab->flags[1] == '0' && tab->width > 0)
		get_display(tab, '0', tab->width - len, 1);
}

t_tab	*d_x(t_tab *tab)
{
	char			*str;
	int				len;

	len = 0;
	str = convert((va_arg(tab->args, int)), 16);
	if (tab->precision > -1 && str)
	{
		str = display_with_precision(str, tab, ft_strlen(str));
		return (tab);
	}
	else if (tab->precision == -1 && str)
		str = ft_strdup(str);
	else if (tab->precision > -1 && !str)
		str = ft_strlcpy("(null)", tab->precision);
	else if (tab->precision == -1 && !str)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	tab->len += len;
	pr_sp(tab, len);
	ft_putstr_fd(str);
	if (tab->flags[0] == '-' && tab->width > 0)
		get_display(tab, ' ', tab->width - len, 1);
	free(str);
	return (tab);
}

t_tab	*d_xmax(t_tab *tab)
{
	char			*str;
	int				len;

	len = 0;
	str = convert_x((va_arg(tab->args, int)), 16);
	if (tab->precision > -1 && str)
	{
		str = display_with_precision(str, tab, ft_strlen(str));
		return (tab);
	}
	else if (tab->precision == -1 && str)
		str = ft_strdup(str);
	else if (tab->precision > -1 && !str)
		str = ft_strlcpy("(null)", tab->precision);
	else if (tab->precision == -1 && !str)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	tab->len += len;
	pr_sp(tab, len);
	ft_putstr_fd(str);
	if (tab->flags[0] == '-' && tab->width > 0)
		get_display(tab, ' ', tab->width - len, 1);
	free(str);
	return (tab);
}
