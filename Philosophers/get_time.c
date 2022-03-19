#include "philosophers.h"

void    get_time(long time, t_philosopher *my_philo)
{
    long            tt;
    long            gg;
    long            raw_time;
    struct timeval  current_time;

	gettimeofday(&current_time, NULL);
    tt = current_time.tv_sec * 1000;
    raw_time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    if (time != 0)
    {
        printf("chi problem f time we dk!\n");
        exit(1);
    }
    gg = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000) - raw_time;
    while (gg < gg + time)
        usleep(gg);
}