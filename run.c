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

t_nurse     init_nurse(t_doc *doc, t_philo *philo, int count)
{
	t_nurse new;

	new.nb = count;
	new.doc = doc;
	new.philo = philo;
    return (new);
}

void        *routine(void *arg)
{
    while(*(((t_philo*)arg)->doc->status) == 1)
    {
        have_to_eat((t_philo*)arg);
        have_to_sleep((t_philo*)arg);
        have_to_think((t_philo*)arg);
    }
    return (NULL);
}

void        *routine_nurse(void *arg)
{
	t_nurse *cat;

	cat = (t_nurse*)arg;

    while(*(cat->doc->status) == 1)
    {
        check_if_dead(cat->philo);
        if (cat->doc->status == 0)
		{
			//pthread_mutex_unlock(&cat->finish);
            return(NULL);
		}
	}
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
    nurse_t = malloc(sizeof(pthread_t) * doc->nb_philo);
    philo = malloc(sizeof(t_philo) * doc->nb_philo);
    nurse = malloc(sizeof(t_nurse) * doc->nb_philo);
    gettimeofday(&tv, NULL);
    doc->start = get_msec(tv.tv_sec, tv.tv_usec);
    while(count < doc->nb_philo)
    {
        philo[count] = init_philo(doc, count);
        nurse[count] = init_nurse(doc, &philo[count], count);
        count++;
    }
    count = 0;
    while (count < doc->nb_philo)
    {
        pthread_create(&philo_t[count], NULL, (void*)routine, (void*)&philo[count]);
        pthread_create(&nurse_t[count], NULL, (void*)routine_nurse, (void*)&nurse[count]);
        count++;
    }
    while (*(doc->status) == 1)
    {
        ;
    }
	pthread_mutex_lock(&doc->finish);
	printf("pas lock\n");
    // count = 0;
    // while(count < doc.nb_philo)
    // {
    //     pthread_join(philo_t[count], NULL);
    //     pthread_join(nurse_t[count], NULL); 
    //     count++;
    // }

    //FAIRE MES FREE
}
