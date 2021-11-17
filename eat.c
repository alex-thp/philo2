#include "philo.h"

void        have_to_eat(t_philo *philo)
{
    int         i;
    struct      timeval tv;

    i = philo->nb;
    if (i % 2 == 1)
        usleep(1);
    take_a_fork(philo, &(philo)->fork);
    if (i == philo->doc.nb_philo - 1)
        take_a_fork(philo, &(philo - i)->fork);
    else{
        take_a_fork(philo, &(philo + 1)->fork);
    }
    if (philo->doc.option == 1 && philo->nb_eat == philo->doc.nb_time_philo_eat)
			check_if_dead(philo);
    print_message(get_timestamp(philo->doc), philo, "is eating");
    gettimeofday(&tv, NULL);
    philo->last_meal = get_msec(tv.tv_sec, tv.tv_usec);
    philo->nb_eat++;
    while (get_time_since_last_meal(philo) < philo->doc.time_to_eat)
		usleep(10);
    pthread_mutex_unlock(&(philo)->fork);
    if (i == philo->doc.nb_philo - 1)
        pthread_mutex_unlock(&(philo - i)->fork);
    else{
        pthread_mutex_unlock(&(philo + 1)->fork);
    }
}

void        take_a_fork(t_philo *philo, pthread_mutex_t *fork)
{
    pthread_mutex_lock(fork);
    print_message(get_timestamp(philo->doc), philo, "has taken a fork");
}
