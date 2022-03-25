/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/25 18:53:30 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
void	take_forks(t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->r_fork]);
	printf("%d %d has taken a fork\n", data->t_eat, philo->id);
	pthread_mutex_lock(&data->forks[philo->l_fork]);
	printf("%d %d has taken a fork\n", data->t_eat, philo->id);
}

void	drop_forks(t_data *data, t_philo *philo)
{
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
}

void	eating(t_data *data)
{
	// philo->r_fork = philo->id;
	// philo->l_fork = philo->id-1;
	printf("it's me %d\n", (data->n_philo));
	// if (philo->id % 2 == 0) // if odd
	// {
	// 	philo->r_fork = (int)(philo->id % data->n_philo);
	// 	philo->l_fork = (int)(philo->id);
	// }
	// else // if even
	// {
	// 	philo->r_fork = (int)(philo->id);
	// 	philo->l_fork = (int)(philo->id % data->n_philo);
	// }
	// printf("hoooo\n");
	// pthread_mutex_lock(&data->forks[philo->r_fork]);
	// printf("%d %d has taken a fork\n", data->t_eat, philo->id);
	// pthread_mutex_lock(&data->forks[philo->l_fork]);
	// printf("%d %d has taken a fork\n", data->t_eat, philo->id);
		
	take_forks(data);
	printf("%d %d is eating\n", data->t_eat, data->philo->id);
	usleep(data->t_eat);
	drop_forks(data, data->philo);
}
*/
void	sleeping(t_data *data, int i)
{
	printf("t_sleep %d\n", data->t_sleep);
	printf("%d %d is sleeping\n", data->t_sleep, data->philo[i].id);
	
	usleep(data->t_sleep*1000);
}

void	thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
}

void	died(t_data *data)
{
	printf("%d %d died\n", data->t_sleep, data->philo->id);
}