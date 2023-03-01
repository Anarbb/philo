/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:40:18 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/02/26 20:00:05 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define LEFT 255
# define RIGHT 256

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philo;
	int				meals;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				num_meals;
	long long		last_meal;
	long long		start_time;
	int				is_eating;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_meals;
	pthread_mutex_t	*forks;
	long long		start_time;
}					t_data;
// utils
void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(const char *str);
long long			ft_get_time(void);
//actions
void				*life(void *arg);
#endif