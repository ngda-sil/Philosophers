/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_du_propre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:26:53 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/18 23:56:46 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_the_mutexes(t_data *a)
{
	int	i;

	i = -1;
	while (++i < a->nb_philo)
		if (pthread_mutex_destroy(&a->fork[i]))
			return (1);
	if (pthread_mutex_destroy(&a->eat))
		return (1);
	if (pthread_mutex_destroy(&a->log))
		return (1);
	if (pthread_mutex_destroy(&a->print))
		return (1);
	if (pthread_mutex_destroy(&a->state))
		return (1);
	return (0);
}

int	clean(t_data *a)
{
	if (destroy_the_mutexes(a))
		return (str_error("Problem destroying the mutexes", 1));
	if (a->fork)
	{
		free(a->fork);
		a->fork = NULL;
	}
	if (a->p)
	{
		free(a->p);
		a->p = NULL;
	}
	return (0);
}
