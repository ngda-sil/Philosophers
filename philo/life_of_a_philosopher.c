/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:48:25 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/19 00:18:23 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_data *a, t_philo *p)
{
	/*if (pthread_mutex_lock(&a->state))
		return (1);*/
	p->nb_meal++;
	if (print_log(a, p, EAT))
		return (1);
	/*if (pthread_mutex_unlock(&a->state))
		return (1);*/
	p->t_last_m = what_time_is_it(a);
	ft_usleep(a->t_eat, a);
	if (a->nb_m_eat != -1)
	{
		if (p->nb_meal == a->nb_m_eat)
		{
			if (pthread_mutex_lock(&a->eat))
				return (1);
			a->full++;
			if (pthread_mutex_unlock(&a->eat))
				return (1);
		}
	}
	return (0);
}

int	ft_fork(t_data *a, t_philo *p)
{
	if (pthread_mutex_lock(&a->fork[(p->id) % a->nb_philo]))
		return (1);
	if (print_log(a, p, LEFT))
		return (1);
	if (a->nb_philo == 1)
	{
		(pthread_mutex_unlock(&a->fork[(p->id) % a->nb_philo]));
		return (1);
	}
	if (pthread_mutex_lock(&a->fork[(p->id - 1) % a->nb_philo]))
		return (1);
	if (print_log(a, p, RIGHT))
		return (1);
	if (ft_eat(a, p))
		return (1);
	if (pthread_mutex_unlock(&a->fork[(p->id) % a->nb_philo]))
		return (1);
	if (pthread_mutex_unlock(&a->fork[(p->id - 1) % a->nb_philo]))
		return (1);
	return (0);
}

int	ft_sleep(t_data *a, t_philo *p)
{
	if (print_log(a, p, SLEEP))
		return (1);
	ft_usleep(a->t_sleep, a);
	if (print_log(a, p, THINK))
		return (1);
	return (0);
}
