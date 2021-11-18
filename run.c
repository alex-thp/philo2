#include "philo.h"

t_philo     init_philo(t_doc *doc, int count)
{
    t_philo new;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    new.nb = count;
    new.last_meal = get_msec(tv.tv_sec, tv.tv_usec);
    new.doc = doc;
    new.status = 1;
    new.nb_eat = 0;
    if (pthread_mutex_init(&(new.fork), NULL) != 0)
        printf("\n mutex init of philo %d failed\n", new.nb);
    return(new);
}

t_nurse     *init_nurse(t_doc *doc, t_philo *philo, int count)
{
	t_nurse *new;

	new = malloc(sizeof(t_nurse));
	new->nb = count;
	new->doc = doc;
	new->philo = philo;
    return (new);
}

void        *routine(void *arg)
{
    while(*(((t_philo*)arg)->doc->status) >= 1)
    {
        have_to_eat((t_philo*)arg);
        have_to_sleep((t_philo*)arg);
        have_to_think((t_philo*)arg);
        if(((t_philo*)arg)->nb_eat == ((t_philo*)arg)->doc->nb_time_philo_eat && ((t_philo*)arg)->doc->option == 1)
            ((t_philo*)arg)->doc->status--;
    }
    return (NULL);
}

void        *routine_nurse(void *arg)
{
	t_nurse *cat;
	int		i;

	cat = (t_nurse*)arg;
	pthread_mutex_lock(&cat->doc->finish);
    while(*(cat->doc->status) >= 1)
    {
		i = 0;
		while (i < cat->nb)
		{
        	check_if_dead(&cat->philo[i]);
        	if (cat->philo[i].status == 0 || cat->doc->status == 0)
			{
				pthread_mutex_unlock(&cat->doc->finish);
            	return(NULL);
			}
			i++;
		}
	}
	pthread_mutex_unlock(&cat->doc->finish);
    return(NULL);
}

void        run(t_doc *doc)
{
    int                 count;
    pthread_t           *philo_t;
    pthread_t           *nurse_t;
    t_philo             *philo;
    t_nurse             *nurse;
    struct timeval      tv;

    count = 0;
    philo_t = malloc(sizeof(pthread_t) * doc->nb_philo);
    nurse_t = malloc(sizeof(pthread_t));
    philo = malloc(sizeof(t_philo) * doc->nb_philo);
    while(count < doc->nb_philo)
    {
        philo[count] = init_philo(doc, count);
		//print_message(get_timestamp(*(philo->doc)), &philo[count], "cree !\n");
        count++;
    }
	nurse = init_nurse(doc, philo, count);
    count = 0;
	gettimeofday(&tv, NULL);
	doc->start = get_msec(tv.tv_sec, tv.tv_usec);
    while (count < doc->nb_philo)
    {
        pthread_create(&philo_t[count], NULL, (void*)routine, (void*)&philo[count]);
        count++;
    }
	pthread_create(nurse_t, NULL, (void*)routine_nurse, (void*)nurse);
    while (*(doc->status) >= 1)
    {
        ;
    }
	pthread_mutex_lock(&doc->finish);
	pthread_mutex_unlock(&doc->finish);
    custom_free(philo_t, nurse_t, doc, philo, nurse);
}
