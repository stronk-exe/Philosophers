/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/19 18:24:03 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	throw_error(void)
{
	printf("opps error\n");
	return (0);
}
/*
int	check_mealsss(t_data *data)
{
	int	i;

	i = 0;
	// while (i < data->n_philo)
	// {
	//	printf("meals %d\n", data->philo.id);
		if (data->philo.meals < data->n_meals)
		{
		//	data->philo.done_eating = 1;
			return (0);
		}
		i++;
//	}
//	printf("wewweew\n");
	return (1);
}
*/

void	*ft_routine(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	data->start_time = get_time();
	while (1)
	{
		eating(data);
		sleeping_thinking(data);
	}
	return (NULL);
}

void	*ft_check(void *d)
{
	t_data	*data;
	long	tim;

	data = d;
	
	while (1)
	{
		tim = get_time();
	//	printf("tim %ld\n", tim - data->philo.last_meal);
		if ((tim - data->philo.last_meal) > data->t_die)
		{
			sem_wait(data->lock);
			int	time = get_time() - data->start_time;
			printf("%d %d died\n", time, data->philo.id);
			sem_post(data->stop);
			exit(0);
		}
		usleep(100);
	}
	
	return (NULL);
}

void	*ft_eating_checker(void *d)
{
	t_data	*data;
	int		i;

	data = d;
	i = -1;
	sem_wait(data->lock);
	while (++i < data->n_philo)
	{
		sem_post(data->lock);
		sem_wait(data->done_eating);
		sem_wait(data->lock);
	}
	sem_post(data->stop);
	return (NULL);
}

int	ft_init(t_data *data)
{
	data->philo.last_meal = get_time();
	if (pthread_create(&data->tid, NULL, &ft_check, data) != 0)
		return (0);
	pthread_detach(data->tid);
	return(1);
}

int	ft_philo(t_data *data)
{
	int	i;

	i = 0;
//	data->start_time = get_time();
	while (i < data->n_philo)
	{
		data->philo.id = i+1;
		data->philo.n_meals = 0;
	//	printf("wrrr\n");
		data->pid[i] = fork();
	//	printf("wrrr\n");
		if (data->pid[i] == -1)
		{
			while (--i >= 0)
				kill(data->pid[i], SIGKILL);
			return (1);
		}
		else if (data->pid[i] == 0)
		{
			ft_init(data);
			
			ft_routine(data);
		}
		i++;
		
	}
	sem_wait(data->stop);
	return (0);
}

void	kill_them(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		kill(data->pid[i], SIGKILL);
		i++;
	}
}

int	big_init(t_data *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->n_meals = ft_atoi(av[5]);
		if (data->n_meals < 0)
			return (throw_error());
		data->nm_ishere = 1;
	}
	if (data->n_philo <= 0 || data->t_die <= 0 || data->t_eat <= 0 || data->t_sleep <= 0)
		return (throw_error());
	data->pid = malloc(sizeof(pid_t) * data->n_philo);
//	memset(data->pid, 0, sizeof(pid_t) * data->n_philo);
	init_semaphores(data);
	init_done_eating(data);
	return (0);
}

int main(int ac, char **av)
{
	t_data data;
	
//	int	n_philo;
//	int	t_sleep;
	if (ac == 5 || ac == 6)
	{
		// data.n_philo = ft_atoi(av[1]);
		// data.t_die = ft_atoi(av[2]);
		// data.t_eat = ft_atoi(av[3]);
		// data.t_sleep = ft_atoi(av[4]);
		// if (ac == 6)
		// {
		// 	data.n_meals = ft_atoi(av[5]);
		// 	if (data.n_meals < 0)
		// 		return (throw_error());
		// 	data.nm_ishere = 1;
		// }
		// if (data.n_philo <= 0 || data.t_die <= 0 || data.t_eat <= 0 || data.t_sleep <= 0)
		// 	return (throw_error());
		// data.pid = malloc(sizeof(pid_t) * data.n_philo);
	//	if (pthread_mutex_init(&data.lock, NULL) != 0)
	//		return (0);
		big_init(&data, ac, av);
	//	init_semaphores(&data);
	//	if (!create_philosophers(&data))
	//		return (0);
	//	printf("well inited\n");
//	printf("is here %d\n", data.nm_ishere);
		ft_philo(&data);
		
		kill_them(&data);
	//	printf("***************\n");
	//	if (!create_threads(&data))
	//		return (0);
	//	sf_salina(&data);
		
	//	pthread_mutex_init(&data.lock, NULL);
	//	printf("hi\n");
	//	printf("time %ld\n", get_time());
	//	printf("ft_time %ld\n", ft_time());
	}
	else
		return (throw_error());
	
}