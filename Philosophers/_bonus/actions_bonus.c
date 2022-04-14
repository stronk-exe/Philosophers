/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/14 00:57:10 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
/*
void	take_forks(t_philo *philo)
{
	if ((philo->id) % 2 == 0 && philo->id != philo->n)
	{
		sem_wait(philo->r_fork);
		sem_wait(philo->l_fork);
		sem_wait(&philo->lock);
		int	time = get_time() - philo->start_time;
		printf("%d %d has taken a fork\n", time, philo->id);
		printf("%d %d has taken a fork\n", time, philo->id);
		sem_post(&philo->lock);
	}
	else
	{
		sem_wait(philo->l_fork);
		sem_wait(philo->r_fork);
		sem_wait(&philo->lock);
		int	time = get_time() - philo->start_time;
		printf("%d %d has taken a fork\n", time, philo->id);
		printf("%d %d has taken a fork\n", time, philo->id);
		sem_post(&philo->lock);
	}
	
}

void	eating(t_philo *philo)
{
	sem_wait(&philo->lock);
	int	gg = get_time() - philo->start_time;
	printf("%d %d is eating\n", gg, philo->id);
	sem_post(&philo->lock);
	philo->meals++;
	philo->last_meal = get_time();
	usleep(philo->t_eat * 1000);
	sem_post(philo->l_fork);
	sem_post(philo->r_fork);
}
*/
void	sleeping(t_data *data)
{
	sem_wait(data->lock);
	int	time = get_time() /*- philo->start_time*/;
	printf("%d %d is sleeping\n", time, data->philo.id);
	sem_post(data->lock);
	usleep(/*philo->t_sleep * */ 1000);
}

void	thinking(t_data *data)
{
	sem_wait(data->lock);
	printf("%d is thinking\n", data->philo.id);
	sem_post(data->lock);
}
/*
void	died(t_philo *philo)
{
	sem_wait(&philo->lock);
	int	time = get_time() - philo->start_time;
	printf("%d %d died\n", time, philo->id);
	sem_post(&philo->lock);
}
*/