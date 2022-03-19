#include "philosophers.h"

int everything_ok(t_philosopher *my_philospher)
{
  //  pthread_mutex_lock(my_philospher->mutex_alive)
    if (!my_philospher->all_alive /*|| my_philospher->meals == my_philospher->nb_meals*/)
        return (0);
    return (1);
}

void    eating(t_philosopher *my_philo)
{
    take_forks(my_philo);
    if(everything_ok(my_philo))
    {
        printf("%d %d is eating\n", my_philo->t_eat, my_philo->id);
        usleep(my_philo->t_eat);
        let_forks(my_philo);
        my_philo->meals++;
    }
    else
        let_forks(my_philo);
}

void    sleeping(t_philosopher *my_philo)
{
    if (everything_ok(my_philo))
    {
        printf("%d %d is sleeping\n", my_philo->t_sleep, my_philo->id);
        usleep(my_philo->t_sleep);
    }   
}

void    thinking(t_philosopher *my_philo)
{
    if (everything_ok(my_philo))
        printf("%d is thinking\n", my_philo->id);
}