/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:07:58 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/11 00:30:53 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
/*
void	take_forks(t_philo *philo)
{
	if ((philo->id) % 2 == 0 && philo->id != philo->n)
	{
		// pthread_mutex_lock(philo->r_fork);
		// pthread_mutex_lock(philo->l_fork);
		// pthread_mutex_lock(&philo->lock);
		sem_open(philo->r_fork,0);
		sem_open(philo->l_fork,0);
		sem_open(philo->lock,0);
		int	time = get_time() - philo->start_time;
		printf("%d %d has taken a fork\n", time, philo->id);
		printf("%d %d has taken a fork\n", time, philo->id);
	//	pthread_mutex_unlock(&philo->lock);
		sem_close(philo->lock);
	}
	else
	{
		// pthread_mutex_lock(philo->l_fork);
		// pthread_mutex_lock(philo->r_fork);
		// pthread_mutex_lock(&philo->lock);
		sem_open(philo->r_fork,0);
		sem_open(philo->l_fork,0);
		sem_open(philo->lock,0);
		int	time = get_time() - philo->start_time;
		printf("%d %d has taken a fork\n", time, philo->id);
		printf("%d %d has taken a fork\n", time, philo->id);
	//	pthread_mutex_unlock(&philo->lock);
		sem_close(philo->lock);
	}
	
}

void	eating(t_philo *philo)
{
//	pthread_mutex_lock(&philo->lock);
	sem_open(philo->lock,0);
	int	gg = get_time() - philo->start_time;
	printf("%d %d is eating\n", gg, philo->id);
	sem_close(philo->lock);
//	pthread_mutex_unlock(&philo->lock);
	philo->meals++;
	//------------------
//	printf("************i'm %d my n meals %d\n", philo->id, philo->meals);
	//------------------
	philo->last_meal = get_time();
	usleep(philo->t_eat * 1000);
	sem_close(philo->l_fork);
	sem_close(philo->r_fork);
//	pthread_mutex_unlock(philo->l_fork);
//	pthread_mutex_unlock(philo->r_fork);
}
*/
void	sleeping(t_philo *philo)
{
//	pthread_mutex_lock(&philo->lock);
	sem_wait(&philo->lock);
	int	time = get_time() - philo->start_time;
	printf("%d %d is sleeping\n", time, philo->id);
	sem_post(&philo->lock);
//	pthread_mutex_unlock(&philo->lock);
	usleep(philo->t_sleep * 1000);
}

void	thinking(t_philo *philo)
{
//	pthread_mutex_lock(&philo->lock);
	sem_wait(&philo->lock);
	printf("%d is thinking\n", philo->id);
	sem_post(&philo->lock);
//	pthread_mutex_unlock(&philo->lock);
}
/*
void	died(t_philo *philo)
{
//	pthread_mutex_lock(&philo->lock);
	sem_open(philo->lock,0);
	int	time = get_time() - philo->start_time;
	printf("%d %d died\n", time, philo->id);
	sem_close(philo->lock);
	pthread_mutex_unlock(&philo->lock);
}
*/