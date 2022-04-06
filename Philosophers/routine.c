/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:13:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/06 17:35:45 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
void	*routine(void *p)
{
//	t_philo *philo;
	t_data	*data;
	int	i;

//	i = 0;
	data = p;
	printf("n philos %d\n", data->n_philo);
//	data = p;
//	take_forks();
//	pthread_mutex_lock(&(philo->lock));
	for(int j=0;j<data->n_philo;j++)
		printf("i'm philo %d\n", data->philo[j].id);
//	while ((cc * 1000) < (time + philo->t_die) *//*&& i < philo->meal*//*)
	while (1)
	{
	//	printf("raw time %ld\n", current_time.tv_sec);
	//	printf("new time %ld\n", current_time.tv_sec + philo->t_die);
		i = 1;
	//	printf("cc %ld\n", cc);
	//	while (i < philo->n_philo)
	//	{
		//	if (philo->n[i] )
		//	eating(data);
			sleeping(data, i);
		//	thinking(philo);
		//	i++;
	///	}
	//	sleeping(philo);
	//	thinking(philo, philo->n[i]);
	//	i++;
	}
//	died(&data);
//	pthread_mutex_destroy(philo->fork);
	return(0);
}
*/
void	*routine(void *p)
{
	t_philo *philo;
//	t_data	*data=NULL;
	int	i;

	philo = p;
//	pthread_mutex_lock(&philo->output);
	while (1)
	{
		i = 0;
		while (i < philo->n)
		{
		//	if (philo->n[i] )
		//	printf("hii\n");
		//	pthread_mutex_lock(&philo->output);
			take_forks(philo);
			eating(philo);
		//	pthread_mutex_unlock(&philo->output);
			if ((get_time() - philo->last_meal) >= (long)philo->t_die)
				died(philo);
		//	if (philo->meals >= 5)
		//		died(philo);
		//	printf("meals %d\n", data->philo[i].meals);
			sleeping(philo);
			thinking(philo);
			
		//	printf("i %d\n", i);
			i++;
		}
	}
//	pthread_mutex_unlock(&philo->output);
//	died(&data);
//	pthread_mutex_destroy(data->philo->fork);
	return(NULL);
}