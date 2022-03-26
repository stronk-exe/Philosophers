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

void	take_forks(t_data *data, int i)
{
	pthread_mutex_lock(&data->forks[data->philo[i].r_fork]);
	printf("%d %d has taken a fork\n", data->t_eat, data->philo[i].id);
//	printf("holaa\n");
	pthread_mutex_lock(&data->forks[data->philo[i].l_fork]);	
	printf("%d %d has taken a fork\n", data->t_eat, data->philo[i].id);
}

void	drop_forks(t_data *data, int i)
{
	pthread_mutex_unlock(&data->forks[data->philo[i].r_fork]);
	pthread_mutex_unlock(&data->forks[data->philo[i].l_fork]);
}

void	eating(t_data *data, int i)
{
	// philo->r_fork = philo->id;
	// philo->l_fork = philo->id-1;
//	printf("it's me %d\n", (data->n_philo));
//	printf("i %d\n", i);
	if (data->philo[i].id % 2 == 0) // if odd
	{
		data->philo[i].r_fork = (data->philo[i].id+1 % data->n_philo);
		data->philo[i].l_fork = (data->philo[i].id);
	}
	else // if even
	{
		data->philo[i].r_fork = data->philo[i].id;
		data->philo[i].l_fork = (data->philo[i].id+1 % data->n_philo);
	}
//	  printf("hoooo\n");
	// pthread_mutex_lock(&data->forks[philo->r_fork]);
	// printf("%d %d has taken a fork\n", data->t_eat, philo->id);
	// pthread_mutex_lock(&data->forks[philo->l_fork]);
	// printf("%d %d has taken a fork\n", data->t_eat, philo->id);
	
//	printf("r fork %d\n", data->philo[i].r_fork);
//	printf("l fork %d\n", data->philo[i].l_fork);

	take_forks(data, i);
	printf("%d %d is eating\n", data->t_eat, data->philo[i].id);
	usleep(data->t_eat * 1000);
	drop_forks(data, i);
	//printf("hoooy\n");
	data->philo[i].meals++;
	data->philo[i].last_meal = get_time();
}

void	sleeping(t_data *data, int i)
{
	printf("t_sleep %d\n", data->t_sleep);
	printf("%d %d is sleeping\n", /*data->t_sleep*/get_time(), data->philo[i].id);
	
	usleep(data->t_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
}

void	died(t_philo *philo)
{
	printf("%d %d died\n", /*data->t_sleep*/get_time(), philo->id);
	/////////////////////////////////////////
	exit(1); //// exit is foorbiden a sssiiii
	/////////////////////////////////////////
}