/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eat_dead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:21:31 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/17 16:21:49 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_dead_philo(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->count_philos)
	{
		pthread_mutex_lock(&main->philos[i].mutex_last_eat);
		if (get_time() - main->philos[i].last_eat > main->time_die)
		{
			pthread_mutex_lock(main->philos[i].mutex_write);
			printf("[%d] : [%lld] Died\n", main->philos[i].id, get_time());
			pthread_mutex_unlock(main->philos[i].mutex_write);
			pthread_mutex_lock(main->philos[i].mutex_die);
			main->die = 1;
			pthread_mutex_unlock(main->philos[i].mutex_die);
			pthread_mutex_unlock(&main->philos[i].mutex_last_eat);
			return (1);
		}
		pthread_mutex_unlock(&main->philos[i].mutex_last_eat);
		i++;
	}
	return (0);
}

int	check_eat_dead(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->count_philos && main->max_eat != -1)
	{
		pthread_mutex_lock(&main->philos[i].mutex_eat);
		if (main->philos[i].count_must_eat >= main->max_eat)
		{
			pthread_mutex_unlock(&main->philos[i].mutex_eat);
			i++;
		}
		else
		{
			pthread_mutex_unlock(&main->philos[i].mutex_eat);
			break ;
		}
	}
	if (i == main->count_philos)
	{
		pthread_mutex_lock(&main->mutex_die);
		main->die = 1;
		pthread_mutex_unlock(&main->mutex_die);
		return (1);
	}
	return (0);
}
