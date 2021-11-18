#include "philo.h"

void    custom_free(pthread_t *philo_t, pthread_t *nurse_t, t_doc *doc, t_philo *philo, t_nurse *nurse)
{
    int     i;

    i = 0;
    while(i < doc->nb_philo)
    {
        pthread_mutex_destroy(&philo[i].fork);
        i++;
    }
    pthread_mutex_destroy(&doc->print);
    pthread_mutex_destroy(&doc->finish);
    free(philo_t);
    free(nurse_t);
    free(nurse);
	free(philo);
}