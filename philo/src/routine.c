/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:04:22 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/04/06 19:53:31 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	my_print(philo, philo->data, "is eating");
	fusleep(philo->data->time_to_eat);
	pthread_mutex_lock(philo->data->eat);
	philo->last_meal = get_time();
	if (philo->data->nb_must != -1)
		philo->nb_meals++;
	pthread_mutex_unlock(philo->data->eat);
}

void	sleeping(t_philo *philo)
{
	my_print(philo, philo->data, "is sleeping");
	fusleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	my_print(philo, philo->data, "is thinking");
}

void	*philo_routine(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->id % 2 == 0)
		usleep(100);
	while (1)
	{
		take_forks(philos);
		eat(philos);
		put_forks(philos);
		sleeping(philos);
		thinking(philos);
	}
	return (NULL);
}
