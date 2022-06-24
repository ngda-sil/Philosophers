/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:46:03 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/24 13:46:03 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

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

int	init_data(int ac, char **av, t_data *a)
{
	a->nb_philo = ft_atoi(av[1]);
	a->t_death = ft_atoi(av[2]);
	a->t_eat = ft_atoi(av[3]);
	a->t_sleep = ft_atoi(av[4]);
	a->nb_m_eat = -1;
	a->full = 0;
	a->death = 0;
	if (ac == 6)
		a->nb_m_eat = ft_atoi(av[5]);
	if (pthread_mutex_init(&a->print, NULL))
		return (1);
	return (0);
}

void	find_r_fork(t_philo *p, int nb_forks)
{
	int	i;

	i = -1;
	while (++i < nb_forks)
	{	
		if (nb_forks == 1)
			p[i].r_fork = &p[i].l_fork;
		else if (i == 0)
			p[i].r_fork = &p[nb_forks - 1].l_fork;
		else
			p[i].r_fork = &p[i - 1].l_fork;
	}
}

int	init_philo(t_data *a)
{
	int	i;

	a->p = ft_calloc(a->nb_philo, sizeof(t_philo));
	if (!a->p)
		return (1);
	i = -1;
	while (++i < a->nb_philo)
	{
		a->p[i].id = i + 1;
		a->p[i].t_last_meal = 0;
		a->p[i].nb_meal = 0;
		a->p[i].is_alive = 0;
		a->p[i].is_full = 0;
		a->p[i].data = a;
		/*a->p[i].r_fork = malloc(sizeof(pthread_mutex_t));
		if (!a->p[i].r_fork)
			return (1);*/
		if (pthread_mutex_init(&a->p[i].l_fork, NULL))
			return (1);
	}
	find_r_fork(a->p, a->nb_philo);
	return (0);
}
