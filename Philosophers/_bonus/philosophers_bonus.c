/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:11:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/04/15 23:28:54 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
/*
int main(int ac, char **av)
{
	t_data data;
	
//	int	n_philo;
//	int	t_sleep;

	if (ac == 5 || ac == 6)
	{
		data.n_philo = ft_atoi(av[1]);
		data.t_die = ft_atoi(av[2]);
		data.t_eat = ft_atoi(av[3]);
		data.t_sleep = ft_atoi(av[4]);
		if (ac == 6)
			data.n_meals = ft_atoi(av[5]);
	//	create_philosophers();
		pthread_mutex_init(&data.lock, NULL);
		printf("hi\n");
		init_forkes(&data);
		printf("hi\n");
		create_threads(&data);
	}
	else
		write(2, "error\n", 6);
	
}



int main(int ac, char **av)
{
	t_data data;
	
//	int	n_philo;
//	int	t_sleep;

	if (ac == 5 || ac == 6)
	{
		data.n_philo = ft_atoi(av[1]);
		data.t_die = ft_atoi(av[2]);
		data.t_eat = ft_atoi(av[3]);
		data.t_sleep = ft_atoi(av[4]);
		if (ac == 6)
		{
			data.n_meals = ft_atoi(av[5]);
			if (data.n_meals < 0)
				return (throw_error());
			data.nm_ishere = 1;
		}
		if (data.n_philo <= 0 || data.t_die <= 0 || data.t_eat <= 0 || data.t_sleep <= 0)
			return (throw_error());
	//	if (pthread_mutex_init(&data.lock, NULL) != 0)
	//		return (0);
		init_semaphores(&data);
		
		if (!create_philosophers(&data))
			return (0);
	//	printf("hii\n");
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
	
}*/

int	throw_error(void)
{
	printf("opps error\n");
	return(0);
}

void	*chh(void *p)
{
	t_philo *philo;
//	t_data	*data=NULL;
//	int	i;

	philo = p;
//	printf("tfo %d\n", philo->id);	
	return(NULL);
}

void	*gg(void *d)
{
	t_data *data;
	long	tim;

	data = d;
	while (1)
	{
		tim = get_time();
		// printf("dd %ld \n", data->philo.last_meal);
		// printf("tim %ld \n", tim);
		// printf("tim-- %ld \n", tim - data->philo.last_meal);
		int	gg = get_time() - data->philo.last_meal;
	//		printf("gg %d \n", gg);
		if (gg > data->t_die)
		{
			sem_wait(data->lock);
			printf("died\n");
			sem_post(data->lock);
			exit(0);	
		}
	}
	return (NULL);
}

int	ft_init(t_data *data)
{
	data->philo.last_meal = get_time();
	if (pthread_create(&data->tid, NULL, &gg, (void*)&data) != 0)
		return (0);
	pthread_detach(data->tid);
//	if (pthread_join(data->tid, NULL) != 0)
//		return (0);
	return(1);
}

int ft_holoa(t_data *data)
{
	int	i=0;

    while (i < data->n_philo)
	{
		data->philo.id = i+1;
		
	//	data->philo.t_eat = data->t_eat;
	//	data->philo.t_sleep = data->t_sleep;
	//	data->philo.t_die = data->t_die;
	//	data->philo.n = data->n_philo;
		//	data->philo.fork = &data->forks[data->philo.id];
		//	data->philo.r_fork = &data->forks[(data->philo.id + 1) % data->n_philo];
		data->philo.meals = 0;
		data->philo.is_dead = 0;
		
	//	data->philo.start_time = get_time();
//		if (data->nm_ishere)
			data->philo.n_meals = data->n_meals;
//		printf("hello %d\n", data->pid[i]);
		
		
		data->pid[i] = fork();
		
		if (data->pid[i] == 0)
		{
		//	printf("holaaa\n");
            ft_init(data);
			routine(data);
		//	pthread_join(data->t, NULL);
			// while (1)
			// {
			// 	if (!check_deadd(data))
			// 	//	return (0);
			// 		exit(1);
			// 	//	break;
			// }
		//    pthread_detach(data->t);
		//	printf("hii\n");
			
		    
		//	printf("hii\n");
		//	ft_init_philo(args);
		//	ft_routine(args);
		}
//		else
//			waitpid(data->pid[i],NULL,0);
		i++;
	}
	return(1);
}



int main(int ac, char **av)
{
	t_data data;
	
//	int	n_philo;
//	int	t_sleep;

	if (ac == 5 || ac == 6)
	{
		data.n_philo = ft_atoi(av[1]);
		data.t_die = ft_atoi(av[2]);
		data.t_eat = ft_atoi(av[3]);
		data.t_sleep = ft_atoi(av[4]);
		if (ac == 6)
		{
			data.n_meals = ft_atoi(av[5]);
			if (data.n_meals < 0)
				return (throw_error());
			data.nm_ishere = 1;
		}
		if (data.n_philo <= 0 || data.t_die <= 0 || data.t_eat <= 0 || data.t_sleep <= 0)
			return (throw_error());
	//	if (pthread_mutex_init(&data.lock, NULL) != 0)
	//		return (0);
		
		init_semaphores(&data);
	//	if (!create_philosophers(&data))
	//		return (0);
	//	printf("well inited\n");
		ft_holoa(&data);
		
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