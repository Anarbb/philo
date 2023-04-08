/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:37:18 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/04/08 15:43:50 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_detach(data->philos[i].thread) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	monitor(t_data *data)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	pthread_mutex_lock(data->eat);
	while (i < data->nb_philos)
	{
		if (data->nb_must != -1)
		{
			max += data->philos->nb_meals;
			if (max > data->nb_philos * data->nb_must)
				return (1);
		}
		if (get_time() - data->philos[i].last_meal > data->time_to_die)
		{
			pthread_mutex_lock(data->print);
			printf("%lld %d died\n", get_time() - data->start_time,
				data->philos[i].id);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(data->eat);
	return (0);
}

int	init(t_data *data, int argc, char **argv)
{
	if (check_args(argv))
	{
		printf("Error: Wrong arguments\n");
		return (1);
	}
	if (init_data(data, argc, argv) == 1)
	{
		printf("Error: Wrong arguments\n");
		return (1);
	}
	if (init_philos(data) == 1)
	{
		printf("Error: Malloc failed\n");
		return (1);
	}
	if (init_mutexes(data) == 1)
	{
		printf("Error: Malloc failed\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	if (init(data, argc, argv) == 1)
		return (1);
	create_threads(data);
	while (1)
	{
		if (monitor(data) == 1)
			break ;
	}
	destory_mutex(data);
	return (0);
}
