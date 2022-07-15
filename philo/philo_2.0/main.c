/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:45:35 by ngda-sil          #+#    #+#             */
/*   Updated: 2022/07/15 20:29:21 by ngda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	a;

	if (check_args(ac, av))
		return (str_error(ARGS, 1));
	if (init_data(ac, av, &a))
		return (str_error(DATA, 1));
	if (init_philo(&a))
	{
		pthread_mutex_destroy(&a.print);
		//destroy fork_mutex
		return (str_error(INIT, 1));
	}
	if (start_sim(&a, a.p))
		return (str_error(SIM, 1));
	return (0);
}
