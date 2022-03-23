/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:13:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/03/23 23:47:50 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *p)
{
	t_philo *philo;
	t_data	data;
//	int	i;

//	i = 0;
	philo = p;
//	data = p;
//	take_forks();
//	pthread_mutex_lock(&(philo->lock));

//	while ((cc * 1000) < (time + philo->t_die) /*&& i < philo->meal*/)
	while (1)
	{
	//	printf("raw time %ld\n", current_time.tv_sec);
	//	printf("new time %ld\n", current_time.tv_sec + philo->t_die);
		
	//	printf("cc %ld\n", cc);
	//	while (i < philo->n_philo)
	//	{
		//	if (philo->n[i] )
			sleeping(&data, philo);
		//	eating(&data, philo);
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