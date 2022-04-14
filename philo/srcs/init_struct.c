/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:51:11 by hucoulon          #+#    #+#             */
/*   Updated: 2022/04/13 18:51:14 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

void	end_prog(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->nb_philo)
	{
		pthread_mutex_destroy(&philo[i].r_f);
		i++;
	}
	pthread_mutex_destroy(&philo->info->dead);
	pthread_mutex_destroy(&philo->info->write);
	pthread_mutex_destroy(&philo->info->eat);
}

void	init_philo_utils(t_info *info, int i)
{
	pthread_mutex_init(&info->philo[i].r_f, NULL);
	if (info->nb_philo == 1)
		info->philo[i].l_f = NULL;
	else if (i == info->nb_philo - 1)
		info->philo[i].l_f = &info->philo[0].r_f;
	else
		info->philo[i].l_f = &info->philo[i + 1].r_f;
	info->philo[i].num_philo = i + 1;
	info->philo[i].nb_eat = 0;
	info->philo[i].l_eat = actual_time();
	info->philo[i].info = info;
}

void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		init_philo_utils(info, i);
		i++;
	}
	i = 0;
	info->start = actual_time();
	while (i < info->nb_philo)
	{
		pthread_create(&info->philo[i].id, NULL, &routine, &info->philo[i]);
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_join(info->philo[i].id, NULL);
		i++;
	}
	end_prog(info->philo);
}

void	init_struct(char **tab, int argc, t_info *info)
{
	pthread_mutex_init(&info->eat, NULL);
	pthread_mutex_init(&info->write, NULL);
	pthread_mutex_init(&info->dead, NULL);
	info->death = 0;
	info->nb_philo = ft_atoi(tab[1]);
	info->t_t_d = ft_atoi(tab[2]);
	info->t_t_e = ft_atoi(tab[3]);
	info->t_t_s = ft_atoi(tab[4]);
	if (argc == 6)
		info->nb_t_e = ft_atoi(tab[5]);
	else
		info->nb_t_e = -1;
}
