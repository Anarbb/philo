/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:03:29 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/04/08 15:20:46 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_must = ft_atoi(argv[5]);
	else
		data->nb_must = -1;
	if (data->nb_philos < 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0 || (argc == 6
			&& data->nb_must < 0))
		return (1);
	data->start_time = get_time();
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
	data->print = malloc(sizeof(pthread_mutex_t));
	data->eat = malloc(sizeof(pthread_mutex_t));
	if (!data->print || !data->forks)
		return (1);
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(data->print, NULL);
	pthread_mutex_init(data->eat, NULL);
	return (0);
}
