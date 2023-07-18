/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:55:40 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/18 15:42:05 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_time(void)
{
	static int			exec_count;
	static long long	start;
	struct timeval		time;

	if (exec_count == 0)
	{
		gettimeofday(&time, NULL);
		start = (time.tv_usec / 1000) + (time.tv_sec * 1000);
		exec_count ++;
	}
	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000) + (time.tv_sec * 1000) - start);
}

int	main(int argc, char **argv)
{
	t_main	main;
	char	**s;

	get_time();
	if (argc != 5 && argc != 6)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	s = splited(argc, argv);
	if (check_sign(s) != 0 || args_count(s) != 0 || \
		check_args(s) != 0 || check_max(s) != 0)
		return (1);
	main_init(&main, s);
	philo_init(&main, s);
	fork_init(&main);
	create_threads(&main);
	program_exit(&main);
	return (0);
}
