/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:49:20 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/25 17:08:02 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_main	main;
	char	**s;

	if (argc != 5 && argc != 6)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	get_time();
	s = splited(argc, argv);
	if (check_sign(s) != 0 || args_count(s) != 0 || \
		check_args(s) != 0 || check_max(s) != 0)
		return (1);
	main_init(&main, s);
	create_process(&main);
	close_sem(&main);
	return (0);
}
