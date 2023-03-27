/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:37:18 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/03/27 13:16:22 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_detach(data->philos[i].thread);
		i++;
	}
	return (0);
}

int	monitor(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (get_time() - data->philos[i].last_meal > data->time_to_die)
		{
			pthread_mutex_lock(data->print);
			printf("%lld %d died\n", get_time() - data->start_time,
					data->philos[i].id);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = calloc(1, sizeof(t_data));
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments");
		return (1);
	}
	if (init_data(data, argc, argv) == 1)
	{
		printf("Error: Wrong arguments");
		return (1);
	}
	if (init_philos(data) == 1)
	{
		printf("Error: Malloc failed");
		return (1);
	}
	if (init_mutexes(data) == 1)
	{
		printf("Error: Malloc failed");
		return (1);
	}
	create_threads(data);
	while (1)
	{
		if (monitor(data) == 1)
			return (0);
		usleep(1000);
	}

	return (0);
}