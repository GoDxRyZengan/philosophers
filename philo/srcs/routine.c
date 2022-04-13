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

void	ft_write(t_info *info, int nb, int act)
{
	pthread_mutex_lock(&info->write);
	if (act == 0)
		printf("%ld %d has taken a fork\n", actual_time() - info->start, nb);
	else if (act == 1)
		printf("%ld %d is eating\n", actual_time() - info->start, nb);
	else if (act == 2)
		printf("%ld %d is sleeping\n", actual_time() - info->start, nb);
	else if (act == 3)
		printf("%ld %d is thinking\n", actual_time() - info->start, nb);
	else if (act == 4)
		printf("%ld %d died\n", actual_time() - info->start, nb);
	pthread_mutex_unlock(&info->write);
}
/*
void	ft_free(t_philo *philo)
{
	pthread_mutex_destroy(&philo->r_f);
	pthread_mutex_destroy(&philo->info->write);
//	free(philo->info->philo);
}*/

void	check_death(t_philo *philo)
{
	if (philo->info->t_t_d < (actual_time() - philo->l_eat))
	{
		pthread_mutex_lock(&philo->info->dead);
		philo->info->death = 1;
		pthread_mutex_unlock(&philo->info->dead);
		ft_write(philo->info, philo->num_philo, 4);
		free(philo);
		exit(0);
	}
}

void	routine_to_sleep_think(t_philo *philo)
{
	ft_write(philo->info, philo->num_philo, 2);
	ft_usleep(philo->info->t_t_s, philo);
	ft_write(philo->info, philo->num_philo, 3);
}

void	routine_to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	pthread_mutex_lock(&philo->r_f);
	ft_write(philo->info, philo->num_philo, 0);
	ft_write(philo->info, philo->num_philo, 0);
	if (philo->info->t_t_d < (actual_time() - philo->l_eat))
	{
		pthread_mutex_lock(&philo->info->dead);
		philo->info->death = 1;
		pthread_mutex_unlock(&philo->info->dead);
		ft_write(philo->info, philo->num_philo, 4);
		free(philo);
		exit(0);
	}
	else
		philo->l_eat = actual_time();
	ft_write(philo->info, philo->num_philo, 1);
	philo->nb_eat++;
	ft_usleep(philo->info->t_t_e, philo);
	pthread_mutex_unlock(&philo->r_f);
	pthread_mutex_unlock(philo->l_f);
	routine_to_sleep_think(philo);
}
