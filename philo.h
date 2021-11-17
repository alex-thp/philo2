#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct  s_doc 
{
                int             nb_philo;
                long int        time_to_die;
                long int        time_to_eat;
                long int        time_to_sleep;
                int             nb_time_philo_eat;
                int             option;
                long int        start; 
                int             *status;
                pthread_mutex_t print;
                pthread_mutex_t finish;
}               t_doc;

typedef struct  s_philo
{
                t_doc               *doc;
                int                 nb;
                long int            last_meal;
                int                 status;
                int                 nb_eat;
                pthread_mutex_t     fork;
}               t_philo;

typedef struct  s_nurse
{
                t_doc               *doc;
                t_philo             *philo;
                int                 nb;
}               t_nurse;

/* 
tools.c
*/

int		ft_atoi(char *str);
int     find_size(long int nb);
char    *itoa(long int nb);
char	*ft_strjoin(char const *s1, char const *s2);
int 	ft_strlen(const char *s);

/* 
parse.c
*/

t_doc   *parse_doc(char **av, int ac);

/* 
run.c
*/

void        run(t_doc *doc);
void        *routine(void *arg);
t_philo     init_philo(t_doc *doc, int count);

/*
eat.c
*/

void        have_to_eat(t_philo *philo);
void        take_a_fork(t_philo *philo, pthread_mutex_t *fork);


/* 
sleep.c
*/

void        have_to_sleep(t_philo* philo);
void        have_to_think(t_philo* philo);

/* 
time.c
*/

long int    get_msec(time_t tv_sec, suseconds_t tv_usec);
long int    get_time_from_start(long int start, long int now);
long int    get_time_since_start(long int start);
long int    get_time_since_last_meal(t_philo *philo);

/* 
print_message.c
*/

long int    get_timestamp(t_doc doc);
void        print_message(long int timestamp, t_philo *philo, char *str);

/*
check.c
*/

void        check_if_dead(t_philo *philo);

#endif