/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:48:25 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/18 17:18:47 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *p)
{
	p->nb_meal++;
	if (print_log(p, EAT))
		return (1);
	p->t_last_m = what_time_is_it(p->data);
	ft_usleep(p->data->t_eat, p->data);
	if (p->data->nb_m_eat != -1)
	{
		if (p->nb_meal == p->data->nb_m_eat)
		{
			pthread_mutex_lock(&p->data->state);
			p->data->full++;
			pthread_mutex_unlock(&p->data->state);
		}
	}
	return (0);
}

int	ft_fork(t_data *a, t_philo *p)
{
	if (pthread_mutex_lock(&a->fork[(p->id) % a->nb_philo]))
		return (1);
	if (print_log(p, LEFT))
		return (1);
	if ((&a->fork[(p->id) % a->nb_philo]) == (&a->fork[(p->id - 1) % a->nb_philo]))
		return (1);
	if (pthread_mutex_lock(&a->fork[(p->id - 1) % a->nb_philo]))
		return (1);
	if (print_log(p, RIGHT))
		return (1);
	ft_eat(p);
	if (pthread_mutex_unlock(&a->fork[(p->id) % a->nb_philo]))
		return (1);
	pthread_mutex_unlock(&a->fork[(p->id - 1) % a->nb_philo]);
	return (0);
}

int	ft_sleep(t_philo *p)
{
	if (print_log(p, SLEEP))
		return (1);
	ft_usleep(p->data->t_sleep, p->data);
	if (print_log(p, THINK))
		return (1);
	return (0);
}
