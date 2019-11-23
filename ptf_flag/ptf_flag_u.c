#include "ptf_flag.h"

static char	*rev_itoa(char *itoa)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = ft_strlen(itoa) - 1;
	while (i < j)
	{
		tmp = itoa[i];
		itoa[i] = itoa[j];
		itoa[j] = tmp;
		i++;
		j--;
	}
	return (itoa);
}


static int	size_itoa(int n)
{
	int len;

	len = 0;
	else if (n == 0)
		return (2);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}


static	u_itoa(unsigned int n)
{
	char	*itoa;
	int	i;

	i = 0;
	if (!(itoa = (char *)malloc(sizeof(*itoa) * size_itoa(n))))
		return (NULL);
	if (n == 0)
		itoa[i++] = '0';
	while (n)
	{
		itoa[i++] = n % 10 + '0';
		n /= 10;
	}
	itoa[i] = 0;
	itoa = rev_itoa(itoa);
	return (itoa);

}

int	ptf_flag_u(va_list ap)
{
	unsigned int 	u;
	char		*s;

	u = va_arg(ap, unsigned int);
	s = u_itoa(u);
	if (!(s))
		return (-1);
	u = 0;
	while (s[u])
	{
		write(1, &s[u], 1);
		u++;
	}
	free(s);
	return (u - 1);
}
