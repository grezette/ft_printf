#include "ptf_flag.h"

int	ptf_flag_c(va_list ap)
{
	char c;

	c = va_arg(ap, char);
	write(1, &c, 1);
	return (0);
}
