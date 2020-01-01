/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 23:16:02 by grezette          #+#    #+#             */
/*   Updated: 2020/01/01 16:12:41 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

int			ft_conv_p(va_list *ap, t_struct *var)
{
	char	*s;
	int		len;
	void	*p;

	p = va_arg(*ap, void *);
	if (!(s = ft_itoa_base((unsigned long)p, "0123456789abcdef")))
	{
		va_end(*ap);
		return (-1);
	}
	len = (int)ft_strlen(s) + 2;
	if (*s == '0' && var->blpr && var->pres == 0)
		len = 2;
	while (var->bfor-- > len)
		var->len += write(1, " ", 1);
	var->len += write(1, "0x", 2);
	while (*s && var->pres--)
		var->len += write(1, s++, 1);
	while (var->aftr-- > len)
		var->len += write(1, " ", 1);
	ft_struct_init(var, 0);
	return (0);
}

static int	ft_dirty(char *s, t_struct *var)
{
	int len;

	if (s[0] == '0' && var->pres == 0)
	{
		len = 0;
		return (len);
	}
	if (s[0] == '-')
		len = ((int)ft_strlen(s) - 1 > var->pres) ? (int)ft_strlen(s) : var->pres + 1;
	else
		len = ((int)ft_strlen(s) > var->pres) ? (int)ft_strlen(s) : var->pres;
	return (len);
}

int			ft_conv_c_prct(va_list *ap, t_struct *var, unsigned char c)
{
	c = (c == 'c') ? va_arg(*ap, int) : '%';
	if (var->bfor > -1 || var->pres > -1)
		while (var->bfor-- > 1 || var->zero-- > 1)
			var->len += write(1, " ", 1);
	while (var->zero-- > 1)
		var->len += write(1, "0", 1);
	var->len += write(1, &c, 1);
	while (var->aftr-- > 1)
		var->len += write(1, " ", 1);
	ft_struct_init(var, 0);
	return (0);
}

int			ft_conv_s(va_list *ap, t_struct *var)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char *);
	var->pres = (var->pres < -1) ? -1 : var->pres;
	len = var->pres;
	if (!s)
		s = ft_strdup("(null)");
	if ((int)ft_strlen(s) < var->pres || var->pres == -1)
		len = ft_strlen(s);
	if (var->zero > -1)
	{
		va_end(*ap);
		return (-1);
	}
	while (var->bfor-- > len)
		var->len += write(1, " ", 1);
	while (s && *s && var->pres--)
		var->len += write(1, s++, 1);
	while (var->aftr-- > len)
		var->len += write(1, " ", 1);
	ft_struct_init(var, 0);
	return (0);
}

int		ft_conv_diuxx(va_list *ap, t_struct *var, unsigned char c)
{
	char	*s;
	char	*tmp;
	int		len;
	int		nblen;

	if (!var->blpr)
		var->pres = -1;
	if (c == 'd' || c == 'i')
		if (!(s = ft_itoa_base(va_arg(*ap, int), "0123456789")))
			return (-1);
	if (c == 'u')
		if (!(s = ft_itoa_base(va_arg(*ap, unsigned int), "0123456789")))
			return (-1);
	if (c == 'x')
		if (!(s = ft_itoa_base(va_arg(*ap, unsigned int), "0123456789abcdef")))
			return (-1);
	if (c == 'X')
		if (!(s = ft_itoa_base(va_arg(*ap, unsigned int), "0123456789ABCDEF")))
			return (-1);
	tmp = s;
	len = ft_dirty(s, var);
	if (var->bfor > -1 || var->pres > -1)
		while (var->bfor-- > len || var->zero-- > len)
			var->len += write(1, " ", 1);
	if (s[0] == '-')
		var->len += write(1, s++, 1);
	while (var->zero-- > len)
		var->len += write(1, "0", 1);
	nblen = ft_strlen(s);
	while (var->pres-- > nblen)
		var->len += write(1, "0", 1);
	while (*s && len)
		var->len += write(1, s++, 1);
	while (var->aftr-- > len)
		var->len += write(1, " ", 1);
	ft_struct_init(var, 0);
	free(tmp);
	tmp = NULL;
	return (0);
}
