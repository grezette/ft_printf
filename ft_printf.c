#include "ft_printf.h"

//%p - %i - %x - %X%

int	ptf_check_flag(const char *s, int i, va_list ap)
{
	int len;

	if (s[i] == 'c')
		len = ptf_flag_c(ap);
	else if (s[i] == 's')
		len = ptf_flag_s(ap);
	else if (s[i] == 'p')
		len = ptf_flag_p(ap);
	else if (s[i] == 'd')
		len = ptf_flag_d(ap);
	else if (s[i] == 'i')
		len = ptf_flag_i(ap);
	else if (s[i] == 'u')
		len = ptf_flag_u(ap);
	else if (s[i] == 'x')
		len = ptf_flag_x(ap);
	else if (s[i] == 'X')
		len = ptf_flag_X(ap);
	else
	{
		write(1, &s[i - 1], 2);
		len = 1;
	}
	return (len);
}

int 	ft_printf(const char *s, ...)
{
	int i;
	int len;
	va_list ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ptf_check_flag(s, i, ap);
		}
		else
			write(1, &s[i], 1);
		len++;
		i++;
	}
	va_end(ap);
	return (len);
}
