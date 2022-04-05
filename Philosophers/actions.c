/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/05 00:31:58 by ael-asri         ###   ########.fr       */
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

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	printf("%ld %d has taken a fork\n", /*data->t_eat*/get_time(), philo->id);
//	printf("holaa\n");
	pthread_mutex_lock(&philo->l_fork);	
	printf("%ld %d has taken a fork\n", /*data->t_eat*/get_time(), philo->id);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}

void	eating(t_philo *philo)
{
//	pthread_mutex_lock(&data->eat);
	// philo->r_fork = philo->id;
	// philo->l_fork = philo->id-1;
//	printf("it's me %d\n", (data->n_philo));
//	printf("i %d\n", i);
//	pthread_mutex_lock(&data->philo[i].lock);
/*	if (philo->id % 2 == 0) // if odd
	{
		philo->r_fork = (philo->id+1 % philo->n);
		philo->l_fork = (philo->id);
	}
	else // if even
	{
		philo->r_fork = philo->id;
		philo->l_fork = (philo->id+1 % philo->n);
	}*/
//	  printf("hoooo\n");
	// pthread_mutex_lock(&data->forks[philo->r_fork]);
	// printf("%d %d has taken a fork\n", data->t_eat, philo->id);
	// pthread_mutex_lock(&data->forks[philo->l_fork]);
	// printf("%d %d has taken a fork\n", data->t_eat, philo->id);
	
//	printf("r fork %d\n", data->philo[i].r_fork);
//	printf("l fork %d\n", data->philo[i].l_fork);

	take_forks(philo);
	printf("%ld %d is eating\n", get_time(), philo->id);
	usleep(philo->t_eat * 1000);
	drop_forks(philo);
	//printf("hoooy\n");
	philo->meals++;
	philo->last_meal = get_time();
//	pthread_mutex_unlock(&data->philo[i].lock);
//	pthread_mutex_unlock(&data->eat);
}

void	sleeping(t_philo *philo)
{
//	printf("t_sleep %d\n", data->t_sleep);
	pthread_mutex_lock(&philo->lock);
	printf("%ld %d is sleeping\n", get_time(), philo->id);
	pthread_mutex_unlock(&philo->lock);
	usleep(philo->t_sleep * 1000);
}


void	thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
}

void	died(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	printf("%ld %d died\n", /*data->t_sleep*/get_time(), philo->id);
	pthread_mutex_unlock(&philo->lock);
	/////////////////////////////////////////
	exit(1); //// exit is foorbiden a sssiiii
	/////////////////////////////////////////
}