/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:51:46 by hucoulon          #+#    #+#             */
/*   Updated: 2022/04/13 18:51:50 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

void	ft_write(t_philo *philo, int nb, int act, char *str)
{
	pthread_mutex_lock(&philo->info->write);
	if (check_stop(philo) == 0)
		printf("%ld %d %s\n", actual_time() - philo->info->start, nb, str);
	if (act == 1)
		printf("%ld %d %s\n", actual_time() - philo->info->start, nb, str);
	pthread_mutex_unlock(&philo->info->write);
}

void	check_death(t_philo *philo)
{
	if (philo->info->t_t_d < (actual_time() - philo->l_eat))
	{
		pthread_mutex_lock(&philo->info->dead);
		philo->info->death = 1;
		pthread_mutex_unlock(&philo->info->dead);
		ft_write(philo, philo->num_philo, 1, "died");
		end_prog(philo);
		exit(0);
	}
}

void	routine_to_sleep_think(t_philo *philo)
{
	ft_write(philo, philo->num_philo, 0, "is sleeping");
	ft_usleep(philo->info->t_t_s, philo);
	ft_write(philo, philo->num_philo, 0, "is thinking");
	ft_usleep(1, philo);
}

void	routine_to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	pthread_mutex_lock(&philo->r_f);
	ft_write(philo, philo->num_philo, 0, "has taken a fork");
	ft_write(philo, philo->num_philo, 0, "has taken a fork");
	check_death(philo);
	if (check_stop(philo) == 0)
		philo->l_eat = actual_time();
	ft_write(philo, philo->num_philo, 0, "is eating");
	pthread_mutex_lock(&philo->info->eat);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->info->eat);
	ft_usleep(philo->info->t_t_e, philo);
	pthread_mutex_unlock(&philo->r_f);
	pthread_mutex_unlock(philo->l_f);
	routine_to_sleep_think(philo);
}
