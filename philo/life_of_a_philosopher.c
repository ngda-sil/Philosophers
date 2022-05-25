/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tracy <tracy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:18:55 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/05/25 03:21:11 by tracy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *p)
{
	p->t_last_meal = what_time_is_it(p->data);
	p->nb_meal++;
	if (print_log(p, EAT))
		return (1);
	usleep(p->data->t_eat * 1000);
	return (0);
}

int	ft_fork(t_philo *p)
{
	if (pthread_mutex_lock(&p->l_fork))
		return (1);
	if (print_log(p, LEFT))
		return (1);
	if (pthread_mutex_lock(p->r_fork))
		return (1);
	if (print_log(p, RIGHT))
		return (1);
	ft_eat(p);
	if (pthread_mutex_unlock(&p->l_fork))
		return (1);
	if (pthread_mutex_unlock(p->r_fork))
		return (1);
	return (0);
}

int	ft_sleep(t_philo *p)
{
	if (print_log(p, SLEEP))
		return (1);
	usleep(p->data->t_sleep * 1000);
	if (print_log(p, THINK))
		return (1);
	return (0);
}

int	ft_die(t_philo *p)
{
	if (p->is_alive == 0)
		if (print_log(p, DEATH))
			return (1);
	return (0);
}
