#include "philo.h"

void        check_if_dead(t_philo *philo)
{
    // if (philo->doc->option == 1 && philo->nb_eat >= philo->doc->nb_time_philo_eat)
    //     *(philo->doc->nb_time_ate) = 0;
    if (get_time_since_last_meal(philo) > philo->doc->time_to_die)
    {
        philo->status = 0;
        *(philo->doc->status) = 0;
        print_message(philo, "died");
    }
}