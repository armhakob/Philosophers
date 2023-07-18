/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:14:54 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/18 15:26:37 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main_init(t_main *main, char **s)
{
	main->count_philos = ft_atoi(s[0]);
	if (main->count_philos == 0)
		return (1);
	main->time_die = ft_atoi(s[1]);
	if (s[4])
		main->max_eat = ft_atoi(s[4]);
	else
		main->max_eat = -1;
	main->die = 0;
	main->philos = (t_philo *)malloc(sizeof(t_philo) * main->count_philos);
	main->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
				* main->count_philos);
	pthread_mutex_init(&main->mutex_die, NULL);
	pthread_mutex_init(&main->mutex_write, NULL);
	return (0);
}

void	philo_init(t_main *main, char **s)
{
	int	i;

	i = 0;
	while (i < main->count_philos)
	{
		main->philos[i].id = i;
		main->philos[i].last_eat = 0;
		main->philos[i].time_eat = ft_atoi(s[2]);
		main->philos[i].time_sleep = ft_atoi(s[3]);
		main->philos[i].count_must_eat = 0;
		main->philos[i].die = &(main->die);
		main->philos[i].mutex_write = &(main->mutex_write);
		main->philos[i].mutex_die = &(main->mutex_die);
		pthread_mutex_init(&(main->philos[i].mutex_eat), NULL);
		pthread_mutex_init(&(main->philos[i].mutex_last_eat), NULL);
		i++;
	}
}

void	fork_init(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->count_philos)
		pthread_mutex_init(&(main->fork[i]), NULL);
	i = 0;
	while (i < main->count_philos)
	{
		if (i == main->count_philos - 1)
		{
			main->philos[i].mutex_left = &(main->fork[i]);
			main->philos[i].mutex_right = &(main->fork[0]);
		}
		else
		{
			main->philos[i].mutex_left = &(main->fork[i]);
			main->philos[i].mutex_right = &(main->fork[i + 1]);
		}
		i++;
	}
}
