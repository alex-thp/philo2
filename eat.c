/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:27:20 by ade-temm          #+#    #+#             */
/*   Updated: 2021/11/23 12:09:09 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	have_to_eat(t_philo *philo)
{
	int				i;
	struct timeval	tv;

	i = philo->nb;
	if (i % 2 == 1)
		usleep(60);
	pthread_mutex_lock(&(philo)->fork);
	if (i == philo->doc->nb_philo - 1)
		pthread_mutex_lock(&(philo - i)->fork);
	else
		pthread_mutex_lock(&(philo + 1)->fork);
	print_message(philo, "has taken a fork");
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
	else
		pthread_mutex_unlock(&(philo + 1)->fork);
}
