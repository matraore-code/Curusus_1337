/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 06:23:23 by matraore          #+#    #+#             */
/*   Updated: 2019/12/22 06:46:40 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>
# include "libft.h"

typedef struct	s_tab
{
	const char	*format;
	char		*f_copy;
	char		*f_treat;
	va_list		args;
	va_list		args_cpy;
	int			len;
	size_t		i;
	long int	precision;
	long int	width;
	char		specifier_flag;
	char		flags[4];
	char		*specifier_mask;
	char		*flags_mask;
	int			point_trouve;
	int			j;
	int			k;
}				t_tab;

int				ft_printf(const char *format, ...);
int				traitement(t_tab *tab);
int				parser(t_tab *tab);
int				find_index(char *tab, char element);
t_tab			*initialize(t_tab *tab);
t_tab			*reinitialize(t_tab *tab);
t_tab			*flags(t_tab *tab);
t_tab			*width(t_tab *tab);
t_tab			*precision(t_tab *tab);
t_tab			*arguments(t_tab *tab);
t_tab			*specifier(t_tab *tab);

t_tab			*d_c(t_tab *tab);
t_tab			*d_s(t_tab *tab);
t_tab			*d_x(t_tab *tab);
t_tab			*d_xmax(t_tab *tab);
t_tab			*d_percent(t_tab *tab);
t_tab			*d_d(t_tab *tab);
t_tab			*d_pvoid(t_tab *tab);
t_tab			*d_unsigned(t_tab *tab);
t_tab			*d_switch(t_tab *tab);
void			get_display(t_tab *tab, char c, int len, int update_len);
void			*fmt(void *dest, int val, size_t len);
char			*convert(unsigned int num, int base);
char			*convert_x(unsigned int num, int base);
int				display_precision(int ptr, int n, int p, int len);
int				ft_nbrlen(int i);

#endif
