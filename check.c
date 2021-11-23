/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:27:51 by ade-temm          #+#    #+#             */
/*   Updated: 2021/11/23 12:18:43 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_if_ate_enought(t_philo *philo)
{
	if (philo->doc->option == 1 && philo->nb_eat
		== philo->doc->nb_time_philo_eat)
		*(philo->doc->status) -= 1;
}

void	check_if_dead(t_philo *philo)
{
	if (get_time_since_last_meal(philo) > philo->doc->time_to_die)
	{
		philo->status = 0;
		*(philo->doc->status) = 0;
		print_message(philo, "died");
	}
}

int	check_params(t_doc doc)
{
	if (doc.nb_philo < 1 || doc.nb_philo > 200)
		return (1);
	if (doc.time_to_die < 0)
		return (1);
	if (doc.time_to_eat < 0)
		return (1);
	if (doc.time_to_eat < 0)
		return (1);
	if (doc.time_to_sleep < 0)
		return (1);
	if (doc.nb_time_philo_eat < 1)
		return (1);
	return (0);
}
