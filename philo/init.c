/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:59:41 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/18 23:51:01 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6)
		return (str_error("Wrong number of arguments", 1));
	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (str_error("Only digits, please !", 1));
		if (atol_pos(av[i]) > INT_MAX || j > 9)
			return (str_error("Enter values between 0 & INT_MAX", 1));
	}
	return (0);
}

void	init_data(int ac, char **av, t_data *a)
{
	a->nb_philo = atol_pos(av[1]);
	a->t_death = atol_pos(av[2]);
	a->t_eat = atol_pos(av[3]);
	a->t_sleep = atol_pos(av[4]);
	a->nb_m_eat = -1;
	a->full = 0;
	a->death = 0;
	a->fork = NULL;
	a->p = NULL;
	if (ac == 6)
		a->nb_m_eat = (int)atol_pos(av[5]);
}

int	init_mutex(t_data *a)
{
	int	i;

	i = -1;
	a->fork = ft_calloc(a->nb_philo, sizeof(pthread_mutex_t));
	if (!a->fork)
		return (str_error("Problem malloc fork", 1));
	while (++i < a->nb_philo)
		if (pthread_mutex_init(&a->fork[i], NULL))
			return (str_error("Problem init mutex ", 1));
	if (pthread_mutex_init(&a->eat, NULL))
		return (str_error("Problem init mutex", 1));
	if (pthread_mutex_init(&a->log, NULL))
		return (str_error("Problem init mutex", 1));
	if (pthread_mutex_init(&a->print, NULL))
		return (str_error("Problem init mutex", 1));
	if (pthread_mutex_init(&a->state, NULL))
		return (str_error("Problem init mutex", 1));
	return (0);
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
		a->p[i].t_last_m = 0;
		a->p[i].nb_meal = 0;
		a->p[i].full = 0;
		a->p[i].data = a;
	}
	return (0);
}
