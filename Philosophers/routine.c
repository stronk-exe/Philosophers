#include "philosophers.h"

/*
void	eating(t_philo *philo)
{
	printf("%d %d has taken a fork\n", philo->t_eat, philo->n);
	printf("%d %d is eating\n", philo->t_eat, philo->n);
	sleep(philo->t_eat);
}

void	sleeping(t_philo *philo, int n)
{
	printf("%d %d is sleeping\n", philo->t_sleep, n);
	usleep(philo->t_sleep);
}

void	thinking(t_philo *philo, int n)
{
	printf("%d %d is thinking\n", philo->t_think, n);
//	sleep(philo->t_think);
}

void	died(t_philo *philo, int n)
{
	printf("%d %d died\n", philo->t_sleep, n);
}

*/


void    *routine(void *my_philo)
{
//    t_philosopher   *my_philo;
    while (everything_ok(my_philo))
    {
        eating(my_philo);
        sleeping(my_philo);
        thinking(my_philo);
    }
    return(my_philo);
}




/*
void	*rrroutine(void *p)
{
	t_philo *philo;
	long time;
	long	cc;
	int	i;
	

	i = 0;
	philo = p;
	
//	cc = current_time.tv_sec * 1000;
//	pthread_mutex_lock(&(philo->lock));*/

//	while ((cc * 1000) < (time + philo->t_die) /*&& i < philo->meal*/)
//	while (1/*someone died || number of meals reached*/)
//	{
//		printf("raw time %ld\n", current_time.tv_sec);
//		printf("new time %ld\n", current_time.tv_sec + philo->t_die);
	//	eating(philo);
	/*	i = 0;
		while (i < philo->n_philo)
		{
		//	if (philo->n[i] )
			sleeping(philo,i);
		//	printf("----\n");
			thinking(philo, i);
		//	printf("----\n");
			i++;
		}
	//	sleeping(philo);
	//	thinking(philo, philo->n[i]);
//		cc = gettimeofday(&current_time, NULL) * 1000;
	//	i++;
	}
//	died(philo, n);
//	pthread_mutex_unlock(&(philo->lock));
	return(0);
}*/