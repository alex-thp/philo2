#include "philo.h"

long int        get_timestamp(t_doc doc)
{
    long int    timestamp;

    timestamp = get_time_since_start(doc.start);
    return (timestamp);
}

char            *get_str(long int timestamp, t_philo *philo, char *str)
{
    char    *time;
    char    *nb_philo;
    char    *to_print;

    time = itoa(timestamp);
    nb_philo = itoa((long int)philo->nb);
    to_print = ft_strjoin(time, nb_philo);
    to_print = ft_strjoin(to_print, str);
    return (to_print);
}

void            print_message(long int timestamp, t_philo *philo, char *str)
{
    if(*(philo->doc.status) == 1 && philo->status == 1)
    {
        pthread_mutex_lock(&philo->doc.print);
        printf("%ld %d %s\n", timestamp, philo->nb + 1, str);
        if (philo->status == 1)
            pthread_mutex_unlock(&philo->doc.print);
    }
}