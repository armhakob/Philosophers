/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:25:52 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/18 15:38:24 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef void	*(*t_thread_idk)(void *);

typedef struct s_philo
{
	int				id;
	int				last_eat;
	int				time_eat;
	int				time_sleep;
	int				count_must_eat;
	int				*die;
	pthread_t		philo;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	*mutex_write;
	pthread_mutex_t	*mutex_left;
	pthread_mutex_t	*mutex_right;
	pthread_mutex_t	*mutex_die;
}	t_philo;

typedef struct s_main
{
	int				die;
	int				max_eat;
	int				time_die;
	int				count_philos;
	t_philo			*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_die;
}	t_main;

int				ft_atoi(char *str);
int				check_args(char **s);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *src);
char			**splited(int argc, char **argv);
int				check_sign(char **str);
int				check_max(char **s);
int				args_count(char **s);
int				main_init(t_main *main, char **s);
void			philo_init(t_main *main, char **s);
void			fork_init(t_main *main);
void			ph_usleep(unsigned long sleep, t_philo *philo);
long long int	get_time(void);
int				is_die(t_philo *philo);
void			routine_norm(t_philo *philo, char *s);
void			*routine(t_philo *philo);
int				check_dead_philo(t_main *main);
int				check_eat_dead(t_main *main);
void			program_exit(t_main *main);
void			create_threads(t_main *main);

#endif