/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:11:46 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/25 17:07:20 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define SEM_FORK		"/sem_fork"
# define SEM_WRITE		"/sem_write"
# define SEM_LAST_EAT	"/sem_last_eat"
# define SEM_EACH_EAT	"/sem_each_eat"

typedef void	*(*t_thread_idk)(void *);

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				last_eat;
	int				time_eat;
	int				time_sleep;
	int				count_must_eat;
	pthread_t		philo;
	sem_t			*sem_each_eat;
	sem_t			*sem_fork;
	sem_t			*sem_write;
	sem_t			*sem_last_eat;
}	t_philo;

typedef struct s_main
{
	int				max_eat;
	int				time_die;
	int				count_philos;
	t_philo			*philos;
}	t_main;

typedef struct s_mix
{
	t_main	*main;
	t_philo	*philo;
}	t_mix;

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

long long int	get_time(void);
void			ph_usleep(unsigned long sleep);
void			ph_print(t_philo *philo, char *s);
void			terminate(t_main *main);

void			main_init(t_main *main, char **s);
void			philo_init(t_philo *philo, char **str, int count_philo);
void			init_sem(t_philo *philo, int count_philo);
void			child_func(t_main *main, int i);
void			child_func_norm(t_philo *philo);
void			create_process(t_main *main);
void			*check_die(t_mix *mix);
void			close_sem(t_main *main);

#endif