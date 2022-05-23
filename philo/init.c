#include "philo.h"

int    check_args(int ac, char **av)
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

void	init_data(int ac, char **av, t_data *a)
{
    a->nb_philo = ft_atoi(av[1]);
    a->t_death = ft_atoi(av[2]);
    a->t_eat = ft_atoi(av[3]);
    a->t_sleep = ft_atoi(av[4]);
    a->nb_m_eat = -1;
    if (ac == 6)
        a->nb_m_eat = ft_atoi(av[5]);
}