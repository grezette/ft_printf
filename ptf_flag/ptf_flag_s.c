#include "ptf_flag.h"

int	ptf_flag_s(va_list ap)
{
	int 	i;
	char 	*s;

	i = 0;
	s = va_arg(ap, char *);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i - 1);
}
