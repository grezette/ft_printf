/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 23:11:31 by grezette          #+#    #+#             */
/*   Updated: 2020/01/01 09:13:29 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>

void		ft_pars_flag_pres(const char **s, va_list *ap, t_struct *var)
{
	int nb;

	nb = 0;
	if (**s == '.')
	{
		var->pres = 0;
		(*s)++;
		if (**s == '*' || ft_isdigit(**s))
		{
			if (**s == '*')
			{
				nb = va_arg(*ap, int);
				(*s)++;
			}
			else
				while (ft_isdigit(**s))
				{
					nb = nb * 10 + **s - '0';
					(*s)++;
				}
			var->pres = nb;
		}
		var->blpr = 1;
	}
}

void		ft_pars_flag_nb(const char **s, va_list *ap, t_struct *var)
{
	int nb;

	nb = 0;
	if (**s == '*' || ft_isdigit(**s))
	{
		if (**s == '*')
		{
			nb = va_arg(*ap, int);
			(*s)++;
		}
		else
			while (ft_isdigit(**s))
			{
				nb = nb * 10 + **s - '0';
				(*s)++;
			}
		if (nb < 0 || var->aftr == 0)
			var->aftr = (nb > 0) ? nb : -nb;
		else if (var->zero == 0)
			var->zero = nb;
		else
			var->bfor = nb;
	}
}

void		ft_pars_flag_mz(const char **s, t_struct *var)
{
	while (**s == '-' || **s == '0')
	{
		/*attention, peut avoir des problemes dans les cas ou on a juste un seul '-'
		  ou '0' et pas de nb apres. Dans ce cas rajouter deux variables boolenes
		  dans la struct et stocker l'espassement dans les trucs prevu a cet effet*/
		if (**s == '-')
			var->aftr = 0;
		else
			var->zero = 0;
		(*s)++;
	}
}
