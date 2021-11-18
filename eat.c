#include "philo.h"

void        have_to_eat(t_philo *philo)
{
    int         i;
    struct      timeval tv;

    i = philo->nb;
    if (i % 2 == 1)
        usleep(60);
	// gettimeofday(&tv, NULL);
	pthread_mutex_lock(&(philo)->fork);
	//print_message(get_time_since_start(philo->doc->start), philo, "has taken a fork");
    if (i == philo->doc->nb_philo - 1)
	{
	    pthread_mutex_lock(&(philo - i)->fork);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(philo + 1)->fork);
		print_message(philo, "has taken a fork");
	}
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	gettimeofday(&tv, NULL);
    philo->last_meal = get_msec(tv.tv_sec, tv.tv_usec);
    philo->nb_eat++;
    while (get_time_since_last_meal(philo) < philo->doc->time_to_eat)
		usleep(250);
    pthread_mutex_unlock(&(philo)->fork);
    if (i == philo->doc->nb_philo - 1)
        pthread_mutex_unlock(&(philo - i)->fork);
    else{
        pthread_mutex_unlock(&(philo + 1)->fork);
    }
}

// void        take_a_fork(t_philo *philo, pthread_mutex_t *fork)
// {
//     pthread_mutex_lock(fork);
//     print_message(get_timestamp(*(philo->doc)), philo, "has taken a fork");
// }
