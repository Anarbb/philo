/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:28:38 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/04/08 15:41:12 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

struct	s_data;
struct	s_philo;

typedef struct s_philo
{
	int				id;
	int				nb_meals;
	long long		last_meal;
	int				dead;
	struct s_data	*data;
	pthread_t		thread;
}					t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must;
	long long		start_time;
	int				total_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*all_eat;
	pthread_mutex_t	*eat;
	t_philo			*philos;
}					t_data;

// init.c
int					init_data(t_data *data, int argc, char **argv);
int					init_philos(t_data *data);
int					init_mutexes(t_data *data);
// main.c
int					create_threads(t_data *data);
int					monitor(t_data *data);
// routine.c
void				*philo_routine(void *philo);
// utils/rout_utils.c
void				put_forks(t_philo *philo);
void				take_forks(t_philo *philo);
void				fusleep(long long usec);
int					check_args(char **av);
// utils/custom.c
long long			get_time(void);
void				my_print(t_philo *philo, t_data *data, char *str);
//utils
void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(const char *str);
void				destory_mutex(t_data *data);
#endif