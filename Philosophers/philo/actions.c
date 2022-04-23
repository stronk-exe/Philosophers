/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/23 02:00:34 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	printf("%d %d has taken a fork\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	printf("%d %d has taken a fork\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->lock);
}

void	eating(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	if (philo->alive)
		printf("%d %d is eating\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->lock);
	philo->last_meal = get_time();
	philo->meals++;
	if (philo->n_meals && (philo->meals >= philo->n_meals))
		philo->done_eating = 1;
	usleep(philo->t_eat * 1000 - 10000);
	ft_gg(philo->t_eat + philo->last_meal);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	sleeping(t_philo *philo)
{
	int		time;
	long	kk;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	if (philo->alive)
		printf("%d %d is sleeping\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->lock);
	kk = get_time();
	usleep(philo->t_sleep * 1000 - 10000);
	ft_gg(philo->t_sleep + kk);
}

void	thinking(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	if (philo->alive)
		printf("%d %d is thinking\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->lock);
}

void	died(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	printf("%d %d died\n", time, philo->id + 1);
}
