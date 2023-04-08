/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rout_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:06:39 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/04/08 15:49:50 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->id
		% philo->data->nb_philos]);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	my_print(philo, philo->data, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->nb_philos]);
	my_print(philo, philo->data, "has taken a fork");
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
