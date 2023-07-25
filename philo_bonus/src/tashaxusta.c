/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tashaxusta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:14:32 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/25 14:33:29 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	ph_usleep(unsigned long sleep)
{
	unsigned long	value;

	value = get_time();
	while (get_time() - value <= sleep)
		usleep(50);
}

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

void	ph_print(t_philo *philo, char *s)
{
	sem_wait(philo->sem_write);
	printf("[%d] : [%lld] %s\n", philo->id + 1, get_time(), s);
	sem_post(philo->sem_write);
}
