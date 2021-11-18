#include "philo.h"

void        have_to_sleep(t_philo* philo)
{
    struct      timeval tv;
    long int    time;

    gettimeofday(&tv, NULL);
    time = get_msec(tv.tv_sec, tv.tv_usec);
    print_message(philo, "is sleeping");
    while (get_time_since_start(time) < philo->doc->time_to_sleep)
        usleep(250);
}

void        have_to_think(t_philo* philo)
{
    print_message(philo, "is thinking");
}