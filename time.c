#include "philo.h"

long int         get_msec(time_t tv_sec, suseconds_t tv_usec)
{
    long int        ret;

    ret = tv_sec * 1000000 + tv_usec;
    ret /= 1000;
    return (ret);
}

long int        get_time_from_start(long int start, long int now)
{
    return (now - start);
}

long int        get_time_since_start(long int start)
{
    struct timeval  tv;
    long int        result;

    gettimeofday(&tv, NULL);
    result = get_msec(tv.tv_sec, tv.tv_usec);
    result -= start;
    return (result);
}

long int        get_time_since_last_meal(t_philo *philo)
{
    struct timeval  tv;
    long int        result;

    gettimeofday(&tv, NULL);
    result = get_msec(tv.tv_sec, tv.tv_usec);
    result -= philo->last_meal;
    return (result);
}