#include "philo.h"

long int         get_msec(time_t tv_sec, suseconds_t tv_usec)
{
    return((tv_sec * 1000000 + tv_usec)/1000);
}

long int        get_time_since_start(long int start)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
	return (get_msec(tv.tv_sec, tv.tv_usec) - start);
}

long int        get_time_since_last_meal(t_philo *philo)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
	return(get_msec(tv.tv_sec, tv.tv_usec) - philo->last_meal);
}