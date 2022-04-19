/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/19 18:28:47 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

// void	eating(t_data *data)
// {
	
// 	sem_wait(data->forks);
// 	sem_wait(data->forks);
// 	sem_wait(data->lock);
// //	printf("nnn\n");
// 	int	time = get_time() - data->start_time;
// 	printf("%d %d has taken a fork\n", time, data->philo.id);
// 	printf("%d %d has taken a fork\n", time, data->philo.id);
// 	sem_post(data->lock);
// /*}
// void	eating(t_data *data)
// {*/
// 	sem_wait(data->lock);
// //	int	gg = get_time() - data->philo.start_time;
// 	printf("%d %d is eating\n", time, data->philo.id);
// 	sem_post(data->lock);
// 	data->philo.meals++;
// //	printf("******i'm %d my meals %d\n", data->philo.id , data->philo.meals);
// 	data->philo.last_meal = get_time();
// 	if (data->nm_ishere && (data->philo.meals >= data->n_meals))
// 		sem_post(data->done_eating);
// 	//	data->philo.done_eating = 1;
// 	usleep(data->t_eat * 1000);
// 	sem_post(data->forks);
// 	sem_post(data->forks);
// }

// void	sleeping_thinking(t_data *data)
// {
// //	printf("chaaa\n");
// 	sem_wait(data->lock);
// 	int	time = get_time() - data->start_time;
// 	printf("%d %d is sleeping\n", time, data->philo.id);
// 	sem_post(data->lock);
// 	usleep(data->t_sleep * 1000);
// /*}
// void	thinking(t_data *data)
// {*/
// 	sem_wait(data->lock);
// 	printf("%d is thinking\n", data->philo.id);
// 	sem_post(data->lock);
// }



void	eating(t_data *data)
{
	int	time = get_time() - data->start_time;
	sem_wait(data->forks);
	sem_wait(data->forks);
	sem_wait(data->lock);
	printf("%d %d has taken a fork\n", \
		time, data->philo.id);
	printf("%d %d has taken a fork\n", \
		time, data->philo.id);
	sem_post(data->lock);
	sem_wait(data->lock);
	printf("%d %d is eating\n", time, \
		data->philo.id);
	sem_post(data->lock);
	data->philo.last_meal = get_time();
	data->philo.meals++;
//	printf("i'm philo %d, i eat kda w kda %d\n", data->philo.id, data->philo.meals);
	if (data->nm_ishere && data->philo.meals >= data->n_meals)
		sem_post(data->done_eating);
	usleep(data->t_eat*1000);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	sleeping_thinking(t_data *data)
{
	int	time = get_time() - data->start_time;
	sem_wait(data->lock);
	printf("%d %d is sleeping\n", \
		time, data->philo.id);
	sem_post(data->lock);
	usleep(data->t_sleep*1000);
	sem_wait(data->lock);
	printf("%d %d is thinking\n", \
		time, data->philo.id);
	sem_post(data->lock);
}

void	died(t_data *data)
{
	sem_wait(data->lock);
	int	time = get_time() - data->philo.start_time;
	printf("%d %d died\n", time, data->philo.id);
	sem_post(data->lock);
}