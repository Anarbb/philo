/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:05:22 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/04/06 18:27:17 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	my_print(t_philo *philo, t_data *data, char *str)
{
	long long	time;

	time = get_time() - data->start_time;
	pthread_mutex_lock(data->print);
	printf("%lld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(data->print);
}

void	destory_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(data->print);
}

void	fusleep(long long usec)
{
	long long st=get_time();
	while (get_time() - st < usec)
		usleep(100);
}