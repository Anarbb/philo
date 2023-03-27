/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:03:29 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/03/27 13:03:47 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philos = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->nb_must = atoi(argv[5]);
	else
		data->nb_must = -1;
	if (data->nb_philos < 0 || data->nb_philos > 200 || data->time_to_die < 60
		|| data->time_to_eat < 60 || data->time_to_sleep < 60 || data->nb_must <
		-1)
		return (1);
	data->start_time = get_time();
	data->is_philo_dead = malloc(sizeof(int) * data->nb_philos);
	if (!data->is_philo_dead)
		return (1);
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		return (1);
	while (i < data->nb_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = get_time();
		data->philos[i].nb_meals = 0;
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (1);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->print, NULL);
	return (0);
}
