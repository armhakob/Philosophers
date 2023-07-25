/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:14:54 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/25 17:08:13 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	main_init(t_main *main, char **s)
{
	t_philo	philo;
	int		i;

	i = 0;
	main->count_philos = ft_atoi(s[0]);
	main->time_die = ft_atoi(s[1]);
	if (s[4])
		main->max_eat = ft_atoi(s[4]);
	else
		main->max_eat = -1;
	main->philos = (t_philo *)malloc(sizeof(t_philo) * main->count_philos);
	philo_init(&philo, s, main->count_philos);
	while (i < main->count_philos)
	{
		main->philos[i] = philo;
		main->philos[i].id = i;
		i++;
	}
}

void	philo_init(t_philo *philo, char **str, int count_philo)
{
	philo->count_must_eat = 0;
	philo->last_eat = 0;
	philo->time_eat = ft_atoi(str[2]);
	philo->time_sleep = ft_atoi(str[3]);
	init_sem(philo, count_philo);
}

void	init_sem(t_philo *philo, int count_philo)
{
	sem_unlink(SEM_EACH_EAT);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_LAST_EAT);
	sem_unlink(SEM_WRITE);
	philo->sem_each_eat = sem_open(SEM_EACH_EAT, O_CREAT, S_IRWXU, 1);
	philo->sem_fork = sem_open(SEM_FORK, O_CREAT, S_IRWXU, count_philo);
	philo->sem_last_eat = sem_open(SEM_LAST_EAT, O_CREAT, S_IRWXU, 1);
	philo->sem_write = sem_open(SEM_WRITE, O_CREAT, S_IRWXU, 1);
	if (philo->sem_each_eat == SEM_FAILED || philo->sem_fork == SEM_FAILED || \
		philo->sem_last_eat == SEM_FAILED || philo->sem_write == SEM_FAILED)
	{
		perror("Error from sem_open");
		exit(EXIT_FAILURE);
	}
}

void	close_sem(t_main *main)
{
	sem_close(main->philos->sem_fork);
	sem_close(main->philos->sem_write);
	sem_close(main->philos->sem_last_eat);
	sem_close(main->philos->sem_each_eat);
	sem_unlink(SEM_LAST_EAT);
	sem_unlink(SEM_EACH_EAT);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_FORK);
	free(main->philos);
}
