/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:27:46 by ade-temm          #+#    #+#             */
/*   Updated: 2021/11/19 16:12:09 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	custom(t_doc *d, t_philo *ph, t_nurse *nu)
{
	int		i;

	i = 0;
	while (i < d->nb_philo)
	{
		pthread_mutex_destroy(&ph[i].fork);
		i++;
	}
	pthread_mutex_destroy(&d->print);
	pthread_mutex_destroy(&d->finish);
	free(nu);
	free(ph);
}

void	custom2(pthread_t *p, pthread_t *n)
{
	free(p);
	free(n);
}
