/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:04:22 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/03/27 14:37:34 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	my_print(philo, philo->data, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	philo->last_meal = get_time();
	if (philo->data->nb_must != -1)
		philo->nb_meals++;
}

void	sleeping(t_philo *philo)
{
	my_print(philo, philo->data, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
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
		usleep(10);
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
