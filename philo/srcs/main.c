/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:51:21 by hucoulon          #+#    #+#             */
/*   Updated: 2022/04/13 18:51:25 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

int	check_stop(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->info->dead);
	i = philo->info->death;
	pthread_mutex_unlock(&philo->info->dead);
	return (i);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->nb_philo == 1)
	{
		pthread_mutex_lock(&philo->r_f);
		ft_usleep(philo->info->t_t_d, philo);
		ft_write(philo, philo->num_philo, "died");
		pthread_mutex_unlock(&philo->r_f);
		return (NULL);
	}
	if (philo->num_philo % 2 == 0)
		usleep(philo->info->nb_t_e / 10);
	if (philo->info->nb_t_e <= 0)
	{
		while (check_stop(philo) == 0)
			routine_to_eat(philo);
	}
	else if (philo->info->nb_t_e > 0)
	{
		while (check_stop(philo) == 0 && (philo->nb_eat < philo->info->nb_t_e))
			routine_to_eat(philo);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (0);
	if ((check_arg(argv)) == -1)
		return (0);
	init_struct(argv, argc, &info);
	info.philo = malloc(sizeof(t_philo) * (info.nb_philo + 1));
	if (!info.philo)
		return (0);
	init_philo(&info);
	free(info.philo);
	return (0);
}
