/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/15 18:44:11 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"


void	take_forks(t_data *data)
{
	sem_wait(data->forks);
	sem_wait(data->forks);
	sem_wait(data->lock);
	int	time = get_time() - data->philo.start_time;
	printf("%d %d has taken a fork\n", time, data->philo.id);
	printf("%d %d has taken a fork\n", time, data->philo.id);
	sem_post(data->lock);
/*}

void	eating(t_data *data)
{*/
	sem_wait(data->lock);
	int	gg = get_time() - data->philo.start_time;
	printf("%d %d is eating\n", gg, data->philo.id);
	sem_post(data->lock);
	data->philo.meals++;
	data->philo.last_meal = get_time();
	usleep(data->t_eat * 1000);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	sleeping(t_data *data)
{
	sem_wait(data->lock);
	int	time = get_time() - data->philo.start_time;
	printf("%d %d is sleeping\n", time, data->philo.id);
	sem_post(data->lock);
	usleep(data->t_sleep * 1000);
/*}

void	thinking(t_data *data)
{*/
	sem_wait(data->lock);
	printf("%d is thinking\n", data->philo.id);
	sem_post(data->lock);
}

void	died(t_data *data)
{
	sem_wait(data->lock);
	int	time = get_time() - data->philo.start_time;
	printf("%d %d died\n", time, data->philo.id);
	sem_post(data->lock);
}
