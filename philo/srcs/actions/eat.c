/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:53:03 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/02/26 18:38:30 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickup_fork(t_philo *philo, int which)
{
	if (which == LEFT)
		pthread_mutex_lock(philo->left_fork);
	else if (which == RIGHT)
		pthread_mutex_lock(philo->right_fork);
	printf("%lld %d has taken a fork\n", ft_get_time() - philo->start_time,
		philo->id);
}

void	putdown_fork(t_philo *philo, int which)
{
	if (which == LEFT)
		pthread_mutex_unlock(philo->left_fork);
	else if (which == RIGHT)
		pthread_mutex_unlock(philo->right_fork);
}

void	eat(t_philo *philo)
{
	pickup_fork(philo, LEFT);
	pickup_fork(philo, RIGHT);
	philo->is_eating = 1;
	printf("%lld %d is eating\n", ft_get_time() - philo->start_time, philo->id);
	usleep(philo->time_to_eat * 1000);
	philo->is_eating = 0;
	philo->last_meal = ft_get_time();
	putdown_fork(philo, LEFT);
	putdown_fork(philo, RIGHT);
}

void	ft_sleep(t_philo *philo)
{
	printf("%lld %d is sleeping\n", ft_get_time() - philo->start_time,
		philo->id);
	usleep(philo->time_to_sleep * 1000);
}

void	*life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(10);
	while (1)
	{
		eat(philo);
		printf("%lld %d is thinking\n", ft_get_time() - philo->start_time,
			philo->id);
		ft_sleep(philo);
	}
	return (NULL);
}
