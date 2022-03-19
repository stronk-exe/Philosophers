#include "philosophers.h"

void    take_forks(t_philosopher *my_philo)
{
    pthread_mutex_lock(my_philo->right_fork);
    printf("%d has taken a fork\n", my_philo->id);
    pthread_mutex_lock(my_philo->left_fork);
    printf("%d has taken a fork\n", my_philo->id);
}

void    let_forks(t_philosopher *my_philo)
{
    pthread_mutex_unlock(my_philo->right_fork);
    pthread_mutex_unlock(my_philo->left_fork);
}

void create_forks(t_philosopher *my_philo)
{
    int i;

    i = 0;
    my_philo->forks = malloc(sizeof(pthread_mutex_t) * my_philo->n_philo);
    while(i < my_philo->n_philo)
    {
        if (pthread_mutex_init(&my_philo->forks[i], NULL) != 0)
            exit(0);
        i++;
    }
}
/*
void    forking(t_philosopher *my_pilo)
{

}*/