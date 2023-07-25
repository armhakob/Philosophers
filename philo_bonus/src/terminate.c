/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:25:26 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/25 14:27:58 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	terminate(t_main *main)
{
	int	i;
	int	status;

	i = 0;
	while (i < main->count_philos)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) > 0)
		{
			i = -1;
			while (++i < main->count_philos)
				kill(main->philos[i].pid, SIGKILL);
			break ;
		}
		i++;
	}
}
