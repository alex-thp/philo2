#include "philo.h"

t_doc   parse_doc(char **av, int ac)
{
    t_doc   result;

    result.status = malloc(sizeof(int));
    *(result.status) = 1;
    result.nb_philo = ft_atoi(av[1]);
    result.time_to_die = ft_atoi(av[2]);
    result.time_to_eat = ft_atoi(av[3]);
    result.time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        result.option = 1;
    else
        result.option = 0;
    if(result.option)
        result.nb_time_philo_eat = ft_atoi(av[5]);
    return (result);
}
