#include "philo.h"

void            print_message(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->doc->print);
    printf("%ld %d %s\n", get_time_since_start(philo->doc->start), philo->nb + 1, str);
    if (philo->status == 1)
        pthread_mutex_unlock(&philo->doc->print);
}