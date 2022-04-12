#include "../include/philo.h"

void	ft_write(t_info *info, int nb, int act)
{
	struct timeval	now;

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

void		check_death(t_philo *philo)
{
	if (philo->info->t_t_d < (actual_time() - philo->l_eat))
	{
		philo->info->death == 1;
		ft_write(philo->info, philo->num_philo, 4);
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
//	printf("%ld\n", actual_time() - philo->l_eat);
	if (philo->info->t_t_d < (actual_time() - philo->l_eat))
	{
		philo->info->death == 1;
		ft_write(philo->info, philo->num_philo, 4);
		exit(0);
	}
	else
		philo->l_eat = actual_time();
//	printf("%d\n", philo->l_eat);
	ft_write(philo->info, philo->num_philo, 1);
	philo->nb_eat++;
	ft_usleep(philo->info->t_t_e, philo);
	pthread_mutex_unlock(&philo->r_f);
	pthread_mutex_unlock(philo->l_f);
	routine_to_sleep_think(philo);
}
