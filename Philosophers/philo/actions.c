/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/21 20:16:07 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
void	take_forks(t_philo *philo)
{
	int	time;

	if ((philo->id) % 2 == 0 && philo->id + 1 != philo->n)
	{
		
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&philo->lock);
		time = get_time() - philo->start_time;
		if (philo->alive)
			printf("%d %d has taken a fork\n", time, philo->id + 1);
		pthread_mutex_unlock(&philo->lock);
		
	
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&philo->lock);
		time = get_time() - philo->start_time;
		if (philo->alive)
			printf("%d %d has taken a fork\n", time, philo->id + 1);
		pthread_mutex_unlock(&philo->lock);
		
		//pthread_mutex_lock(philo->l_fork);
		
		// if (philo->alive)
		// {
		// 	printf("%d %d has taken a fork\n", time, philo->id + 1);
		// 	printf("%d %d has taken a fork\n", time, philo->id + 1);
		// }
		// pthread_mutex_unlock(philo->r_fork);
		// pthread_mutex_unlock(philo->l_fork);
		
	}
	else
	{
		
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(&philo->lock);
		time = get_time() - philo->start_time;
		if (philo->alive)
			printf("%d %d has taken a fork\n", time, philo->id + 1);
		pthread_mutex_unlock(&philo->lock);
		
		
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(&philo->lock);
		time = get_time() - philo->start_time;
		if (philo->alive)
			printf("%d %d has taken a fork\n", time, philo->id + 1);
		pthread_mutex_unlock(&philo->lock);
		
		
		// pthread_mutex_unlock(philo->l_fork);
		// pthread_mutex_unlock(philo->r_fork);
	}
}
*/

void	take_forks(t_philo *philo)
{
	int	time;

	// if ((philo->id) % 2 == 0 /*&& philo->id != philo->n*/)
	// {
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
		time = get_time() - philo->start_time;
		if (philo->alive)
		{
		pthread_mutex_lock(&philo->lock);
		//	printf("%d %d has taken a fork\n", time, philo->id + 1);
			printf("%d %d has taken a fork\n", time, philo->id + 1);
		pthread_mutex_unlock(&philo->lock);
		pthread_mutex_lock(&philo->lock);
			printf("%d %d has taken a fork\n", time, philo->id + 1);
		//	printf("%d %d has taken a fork\n", time, philo->id + 1);
		pthread_mutex_unlock(&philo->lock);
		}
	// }
	// else
	// {
	// 	pthread_mutex_lock(philo->l_fork);
	// 	pthread_mutex_lock(philo->r_fork);
	// 	pthread_mutex_lock(&philo->lock);
	// 	time = get_time() - philo->start_time;
	// 	if (philo->alive)
	// 	{
	// 		printf("%d %d has taken a fork\n", time, philo->id + 1);
	// 		printf("%d %d has taken a fork\n", time, philo->id + 1);
	// 	}
	// 	pthread_mutex_unlock(&philo->lock);
	// }
}

void	eating(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	if (philo->alive)
		printf("%d %d is eating\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->lock);
	philo->meals++;
	philo->last_meal = get_time();
	if (philo->n_meals && (philo->meals >= philo->n_meals))
		philo->done_eating = 1;
//	printf("*********I'm %d, I eat %d\n", philo->id, philo->meals);
	ft_usleep(philo->last_meal, philo->t_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	sleeping(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = get_time() - philo->start_time;
	if (philo->alive)
		printf("%d %d is sleeping\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(get_time(), philo->t_sleep);
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
//	pthread_mutex_unlock(&philo->lock);
}
