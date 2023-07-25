/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:06:15 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/25 17:07:43 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	*check_die(t_mix *mix)
{
	while (1)
	{
		sem_wait(mix->philo->sem_last_eat);
		if (get_time() - mix->philo->last_eat > mix->main->time_die)
		{
			sem_wait(mix->philo->sem_write);
			printf("[%d] : [%lld] %s\n", mix->philo->id + 1, \
				get_time(), "Died");
			sem_post(mix->philo->sem_last_eat);
			exit(EXIT_FAILURE);
		}
		sem_post(mix->philo->sem_last_eat);
		sem_wait(mix->philo->sem_each_eat);
		if (mix->philo->count_must_eat == mix->main->max_eat && \
			mix->main->max_eat != -1)
		{
			sem_post(mix->philo->sem_each_eat);
			break ;
		}
		sem_post(mix->philo->sem_each_eat);
	}
	return (NULL);
}

void	child_func_norm(t_philo *philo)
{
	sem_wait(philo->sem_fork);
	ph_print(philo, "Took the rigth fork");
	sem_wait(philo->sem_fork);
	ph_print(philo, "Took the left fork");
	ph_print(philo, "Is eating");
	sem_wait(philo->sem_last_eat);
	philo->last_eat = get_time();
	sem_post(philo->sem_last_eat);
	ph_usleep(philo->time_eat);
	sem_wait(philo->sem_each_eat);
	philo->count_must_eat++;
	sem_post(philo->sem_each_eat);
	sem_post(philo->sem_fork);
	sem_post(philo->sem_fork);
	sem_wait(philo->sem_each_eat);
}

void	child_func(t_main *main, int i)
{
	t_philo	*philo;
	t_mix	mix;

	philo = &main->philos[i];
	mix.main = main;
	mix.philo = philo;
	pthread_create(&philo->philo, NULL, (t_thread_idk)(&check_die), &mix);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		child_func_norm(philo);
		if (philo->count_must_eat == main->max_eat && main->max_eat != -1)
		{
			sem_post(philo->sem_each_eat);
			break ;
		}
		sem_post(philo->sem_each_eat);
		ph_print(philo, "Is sleeping");
		ph_usleep(philo->time_sleep);
		ph_print(philo, "Is thinking");
	}
	pthread_join(philo->philo, NULL);
	exit(EXIT_SUCCESS);
}

void	create_process(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->count_philos)
	{
		main->philos[i].pid = fork();
		if (main->philos[i].pid < 0)
		{
			perror("Error from fork:");
			exit(EXIT_FAILURE);
		}
		if (main->philos[i].pid == 0)
			child_func(main, i);
		i++;
	}
	terminate(main);
}
