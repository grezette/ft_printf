#include "ptf_flag.h"

int	ptf_flag_d(va_list ap)
{
	int	d;
	char	*s;

	d = va_arg(ap, int);
	s = ft_itoa(d);
	if (!(s))
		return (-1);
	d = 0;
	while (s[d])
	{
		write(1, &s[d], 1);
		d++;
	}
	free(s);
	return (d - 1);
}
