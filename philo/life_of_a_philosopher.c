/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_a_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:18:55 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/06/04 00:38:47 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *p)
{
	p->nb_meal++;
	if (print_log(p, EAT))
		return (1);
	p->t_last_meal = what_time_is_it(p->data);
	ft_usleep(p->data->t_eat, p->data);
	if (p->nb_meal == p->data->nb_m_eat)
		p->data->full++;
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
	if (pthread_mutex_unlock(&p->l_fork) || pthread_mutex_unlock(p->r_fork))
		return (1);
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

