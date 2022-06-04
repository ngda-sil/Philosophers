/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:38:51 by tracy             #+#    #+#             */
/*   Updated: 2022/06/04 00:38:50 by ngda-sil         ###   ########.fr       */
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
		return (str_error(INIT, 1));
	if (start_sim(&a))
		return (str_error(SIM, 1));
	return (0);
}
