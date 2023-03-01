/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:20:27 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/02/26 20:00:16 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <libc.h>

int	ft_error(char *str, int code)
{
	printf("%s", str);
	return (code);
}

static int	ft_init(t_data *data, int argc, char **argv)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->total_meals = ft_atoi(argv[5]);
	else
		data->total_meals = -1;
	data->forks = (pthread_mutex_t *)ft_calloc(data->num_of_philo,
			sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	data->philo = (t_philo *)ft_calloc(data->num_of_philo,
			sizeof(t_philo));
	if (!data->philo)
		return (1);
	return (0);
}

int	ft_create_threads(t_data *data)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = (pthread_t *)ft_calloc(data->num_of_philo, sizeof(pthread_t));
	if (!threads)
		return (1);
	while (i < data->num_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].num_of_philo = data->num_of_philo;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].left_fork = data->forks + i;
		data->philo[i].right_fork = data->forks + (i + 1) % data->num_of_philo;
		data->philo[i].last_meal = data->start_time;
		data->philo[i].start_time = data->start_time;
		usleep(100);
		if (pthread_create(&threads[i], NULL, life, &data->philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(threads[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

void	monitoring(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->num_of_philo)
		{
			if (ft_get_time() - data->philo[i].last_meal > data->time_to_die)
			{
				printf("%lld %d died\n", ft_get_time() - data->start_time, i
					+ 1);
				return ;
			}
			if (data->total_meals != -1
				&& data->philo[i].meals >= data->total_meals)
				data->num_of_philo--;
			i++;
		}
		if (data->num_of_philo <= 0)
			return ;
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (ft_error("Error: invalid number of arguments", 1));
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (ft_error("Error: allocating memory for philo failed", 1));
	if (ft_init(data, argc, argv))
		return (ft_error("Error: can't initiate the philos", 1));
	data->start_time = ft_get_time();
	if (ft_create_threads(data))
		return (ft_error("Error: pthread_create failed", 1));
	while (1)
		monitoring(data);
	return (0);
}
