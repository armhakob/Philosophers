/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:09:00 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/17 16:29:51 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ph_usleep(unsigned long sleep, t_philo *philo)
{
	unsigned long	value;

	value = get_time();
	while (!is_die(philo))
	{
		if (get_time()- value <= sleep)
			usleep(50);
		else
			break ;
	}
}

int	is_die(t_philo *philo)
{
	int	tmp;

	tmp = 0;
	pthread_mutex_lock(philo->mutex_die);
	tmp = *(philo->die);
	pthread_mutex_unlock(philo->mutex_die);
	return (tmp);
}

void	routine_norm(t_philo *philo, char *s)
{
	pthread_mutex_lock(philo->mutex_write);
	if (!is_die(philo))
		printf("[%d] : [%lld] %s", philo->id + 1, get_time(), s);
	pthread_mutex_unlock(philo->mutex_write);
}

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!is_die(philo))
	{
		pthread_mutex_lock(philo->mutex_right);
		routine_norm(philo, "Took the rigth fork\n");
		pthread_mutex_lock(philo->mutex_left);
		routine_norm(philo, "Took the left fork\n");
		routine_norm(philo, "Is eating\n");
		pthread_mutex_lock(&philo->mutex_last_eat);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->mutex_last_eat);
		ph_usleep(philo->time_eat, philo);
		pthread_mutex_lock(&philo->mutex_eat);
		philo->count_must_eat++;
		pthread_mutex_unlock(&philo->mutex_eat);
		pthread_mutex_unlock(philo->mutex_right);
		pthread_mutex_unlock(philo->mutex_left);
		routine_norm(philo, "Is sleeping\n");
		ph_usleep(philo->time_sleep, philo);
		routine_norm(philo, "Is thinking\n");
	}
	return (0);
}

void	create_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->count_philos)
	{
		pthread_create(&main->philos[i].philo, NULL, \
			(t_thread_idk)&routine, &main->philos[i]);
		i++;
	}
	while (1)
	{
		if (check_dead_philo(main) == 1 || check_eat_dead(main) == 1)
			break ;
	}
	i = 0;
	while (i < main->count_philos && main->count_philos > 1)
	{
		pthread_join(main->philos[i].philo, NULL);
		i++;
	}
}