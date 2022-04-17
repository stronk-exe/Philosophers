/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/17 18:41:02 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	int	time;

	if ((philo->id) % 2 == 0 && philo->id != philo->n)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&philo->lock);
		time = get_time() - philo->start_time;
		printf("%d %d has taken a fork\n", time, philo->id);
		printf("%d %d has taken a fork\n", time, philo->id);
		pthread_mutex_unlock(&philo->lock);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&philo->lock);
		time = get_time() - philo->start_time;
		printf("%d %d has taken a fork\n", time, philo->id);
		printf("%d %d has taken a fork\n", time, philo->id);
		pthread_mutex_unlock(&philo->lock);
	}
}

void	eating(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	printf("%d %d is eating\n", time, philo->id);
	pthread_mutex_unlock(&philo->lock);
	philo->meals++;
	philo->last_meal = get_time();
//	ft_usleep(philo->t_eat * 1000);
	usleep(philo->t_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	printf("%d %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(&philo->lock);
//	ft_usleep(philo->t_sleep * 1000);
	usleep(philo->t_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	printf("%d is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->lock);
}

void	died(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	printf("%d %d died\n", time, philo->id);
	pthread_mutex_unlock(&philo->lock);
}
