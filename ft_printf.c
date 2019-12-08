#include "ft_printf.h"

// cspdiuxX%
// -0.*

int		pf_applide_flag()
{
	
}

int		pf_check_order_flag(const char *s, int i, int k)
{
	int bol[4];

	while (i < k)
	{
		if (s[i] == '-')
			bol[0] = 1;
		else if (s[i] == '0')
			bol[1] = 1;
		else if (s[i] == '.')
			bol[2] += 1;
		else if (s[i] == '*')
			bol[3] += 1;
		if ((s[i] == '-' && (bol[2] || bol[3])) || (s[i] == '0' && bol[3] && !(bol[2])) ||
				(s[i] == '*' && bol[2]) || bol[2] > 1 || bol[3] > 1)
			return (0);
		i++;
	}
	return (1);
}

int		pf_check_convert(const char *s, va_list ap, int *i, int k)
{
	int j;

	j = *i;
	while (++j < k)
		if ((s[j] == '0' && (s[k] == 'c' || s[k] == 's' || s[k] == 'p')) ||
				(s[j] == '.' && (s[k] == 'c' || s[k] == 'p')) ||
				((ft_isdigit(s[*i + 1] && s[*i + 1] != '0') && (s[j] == '-' || s[j] == '*'))))
			return (0);
	if (!(pf_check_order_flag(*s, *i, k)))
		return (0);
	
}

int		ft_printf(const char *s, ...)
{
	va_list ap;
	int		i;
	int		j;
	int		len;

	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			j = 1;
			//check si on voulait juste afficher '%'
			if (s[i + j] == '%')
			{
				len += write(1, "%", 1);
				i += 2
			}
			//avance tant que l'on trouve des flags
			else
			{
				while (ft_isdigit(s[i + j]) || s[i + j] == '-' ||
						s[i + j] == '.' || s[i + j] == '*')
					j++;
				//check si le flag est valide
				if ((s[i + j] != 'c' && s[i + j] != 's' && s[i + j] != 'p' && s[i + j] != 'd' &&
							s[i + j] != 'i' && s[i + j] != 'u' && s[i + j] != 'x' &&
							s[i + j] != 'X') || !(len += pf_check_convert(s, ap, &i, i + j)))
				// affiche le '%' si le flag n'est pas valide et defacto affiche les 'flags' lors du prochain while
					return (0);
			}
		}
		//Lit tant que s n'est pas finis et aue l'on ne trouve pas de '%'
		while (s[i] && s[i++] != '%')
			len += write(1, &s[i], 1);
	}
	return (len);
}
