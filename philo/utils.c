#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_isspace(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if ((res > LONG_MAX / 10) || (res == LONG_MAX / 10 && *str > '7'))
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		res = res * 10 + (*str++ - '0');
	}
	return ((int)(sign * res));
}