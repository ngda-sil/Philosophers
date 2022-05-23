#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int    check_args(int ac, char **av, t_data *a)
{
    int i;
    int j;
	
    if (ac != 5 && ac != 6)
        return (1);
    i = 0;
    while (++i < ac)
    {
        j = -1;
        while (av[i][++j])
            if (!ft_isdigit(av[i][j]))
                return (1);
    }
	return (0);
}