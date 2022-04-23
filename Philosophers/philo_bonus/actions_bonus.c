/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/23 02:56:43 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	eating(t_data *data)
{
	int	time;

	sem_wait(data->forks);
	sem_wait(data->lock);
	time = get_time() - data->start_time;
	printf("%d %d has taken a fork\n", \
		time, data->philo.id);
	sem_post(data->lock);
	sem_wait(data->forks);
	sem_wait(data->lock);
	printf("%d %d has taken a fork\n", \
		time, data->philo.id);
	sem_post(data->lock);
	sem_wait(data->lock);
	time = get_time() - data->start_time;
	printf("%d %d is eating\n", time, \
		data->philo.id);
	sem_post(data->lock);
	data->philo.last_meal = get_time();
	data->philo.meals++;
	if (data->nm_ishere && data->philo.meals >= data->n_meals)
		sem_post(data->done_eating);
	usleep(data->t_eat * 1000 - 10000);
	ft_gg(data->t_eat + data->philo.last_meal);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	sleeping_thinking(t_data *data)
{
	int		time;
	long	kk;

	sem_wait(data->lock);
	time = get_time() - data->start_time;
	printf("%d %d is sleeping\n", time, data->philo.id);
	sem_post(data->lock);
	kk = get_time();
	usleep(data->t_sleep * 1000 - 10000);
	ft_gg(data->t_sleep + kk);
	sem_wait(data->lock);
	time = get_time() - data->start_time;
	printf("%d %d is thinking\n", time, data->philo.id);
	sem_post(data->lock);
}

void	died(t_data *data)
{
	sem_wait(data->lock);
	printf("%ld %d died\n", get_time() - data->start_time, data->philo.id);
}
