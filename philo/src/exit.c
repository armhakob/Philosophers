/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:22:21 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/17 16:27:08 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	program_exit(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->count_philos)
	{
		pthread_mutex_destroy(&main->fork[i]);
		pthread_mutex_destroy(&(main->philos[i].mutex_eat));
		pthread_mutex_destroy(&(main->philos[i].mutex_last_eat));
		i++;
	}
	pthread_mutex_destroy(&main->mutex_die);
	pthread_mutex_destroy(&main->mutex_write);
	free(main->philos);
	free(main->fork);
}
