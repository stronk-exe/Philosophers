/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:13:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/14 21:19:19 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
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
int	routine(t_data *data)
{
//	t_philo *philo;
//	t_data	*data=NULL;
//	int	i;

//	philo = p;
//	pthread_mutex_lock(&philo->output);
//	while (!philo->is_dead)
//	while (!philo->is_dead)
int i=0;
	while (i<5)
//	while (1)
	{
		//	check_dead(philo);
	//	i = 0;
//		while (philo->is_dead)
	//	while (i < philo->n)
	//	{
		//	if (philo->n[i] )
		//	printf("hii\n");
		//	pthread_mutex_lock(&philo->output);
		//	if (philo->is_dead)
		//		return (NULL);
			take_forks(data);
		//	check_dead(philo);
		//	if (philo->is_dead)
		//		return (NULL);
			eating(data);
		//	check_dead(philo);
		//	if (philo->is_dead)
		//		return (NULL);
		//	pthread_mutex_unlock(&philo->output);
		//	if ((get_time() - philo->last_meal) >= (long)philo->t_die)
		//		died(philo);
		//	if (philo->meals >= 5)
		//		died(philo);
//			printf("i'm philo %d\n", philo->id);
			sleeping(data);
		//	check_dead(philo);
		//	if (philo->is_dead)
		//		return (NULL);
			thinking(data);
		//	check_dead(philo);
		//	if (philo->is_dead)
		//		return (NULL);
		//	printf("i %d\n", i);
			i++;
	//	}
	}
//	pthread_mutex_unlock(&philo->output);
//	died(&data);
//	pthread_mutex_destroy(data->philo->fork);
	exit(1);
	return(0);
	
}