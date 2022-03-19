#include "philosophers.h"

void    threading(t_philosopher *my_philo)
{
    int i;
    pthread_t   *tid;

    i = 0;
    tid = malloc(sizeof(pthread_t) * my_philo->n_philo);
    if (!tid)
        exit(1);
    printf("n %d\n", my_philo->n_philo);
    while (i < my_philo->n_philo)
    {
        pthread_mutex_init(my_philo[i].must_eat, NULL);
        if (pthread_create(&tid[i], NULL, routine, (void *)&my_philo[i]) != 0)
            exit(1);
        i++;
    }
    i=0;
    printf("i %d\n", i);
    while (i < my_philo->n_philo)
    {
        if (pthread_join(tid[i], NULL) != 0)
            exit(1);
        i++;
    }
    printf("i %d\n", i);

}

void create_philosophers(t_philosopher *philosopher)
{
    int i;
 //   t_philosopher *philosopher;

//    philosopher = malloc(sizeof(t_philosopher)*my_philo->n_philo);
 //   if (!philosopher)
  //      exit(1);
    i = 0;
    while (i < philosopher->n_philo)
    {
        philosopher[i].id = i+1;
        philosopher[i].meals = 0;
    //    pthread_mutex_init(philosopher[i].must_eat, NULL);
        i++;
    }
 //   printf("hii\n");
    printf("bp %d\n", philosopher->n_philo);
  //  threading(philosopher);
//    printf("hii\n");

    i = 0;
    pthread_t   *tid;

    i = 0;
    tid = malloc(sizeof(pthread_t) * philosopher->n_philo);
    if (!tid)
        exit(1);
    printf("nnn %d\n", philosopher->n_philo);
    while (i < philosopher->n_philo)
    {
    //    if (pthread_mutex_init(philosopher[i].must_eat, NULL) != 0)
      //      exit(1);
        if (pthread_create(&tid[i], NULL, routine, (void *)&philosopher[i]) != 0)
            exit(1);
        i++;
    }
    printf("hii\n");
    i=0;
    printf("i %d\n", i);
    while (i < philosopher->n_philo)
    {
        if (pthread_join(tid[i], NULL) != 0)
            exit(1);
        i++;
    }
}