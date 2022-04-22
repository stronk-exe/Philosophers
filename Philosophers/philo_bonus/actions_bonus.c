/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/22 18:25:55 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	take_forks(t_data *data)
{
	sem_wait(data->forks);
	sem_wait(data->lock);
	printf("%ld %d has taken a fork\n",
		get_time() - data->start_time, data->philo.id);
	sem_post(data->lock);
	sem_wait(data->forks);
	sem_wait(data->lock);
	printf("%ld %d has taken a fork\n",
		get_time() - data->start_time, data->philo.id);
	sem_post(data->lock);
}

void	eating(t_data *data)
{
	sem_wait(data->lock);
	printf("%ld %d is eating\n", get_time() - data->start_time, data->philo.id);
	sem_post(data->lock);
	data->philo.meals++;
	data->philo.last_meal = get_time();
	if (data->nm_ishere && data->philo.meals >= data->n_meals)
		sem_post(data->done_eating);
	ft_usleep(data->philo.last_meal, data->t_eat);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	sleeping(t_data *data)
{
	sem_wait(data->lock);
	printf("%ld %d is sleeping\n",
		get_time() - data->start_time, data->philo.id);
	sem_post(data->lock);
	ft_usleep(get_time(), data->t_sleep);
}

void	thinking(t_data *data)
{
	sem_wait(data->lock);
	printf("%ld %d is thinking\n",
		get_time() - data->start_time, data->philo.id);
	sem_post(data->lock);
}

void	died(t_data *data)
{
	int	time;

	sem_wait(data->lock);
	time = get_time() - data->philo.start_time;
	printf("%d %d died\n", time, data->philo.id);
}
