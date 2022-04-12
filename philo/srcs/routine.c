#include "../include/philo.h"

void	ft_write(t_info *info, int nb, int act)
{
	struct timeval	now;

	pthread_mutex_lock(&info->write);
	gettimeofday(&now, NULL);
//	printf("TRY%.0f\n", (10e3 * ((now.tv_sec - info->start.tv_sec) + 10e-6 * (now.tv_usec - info->start.tv_usec))));
	if (act == 0)
		printf("%.0f %d has taken a fork\n", (10e3 * ((now.tv_sec - info->start.tv_sec) + 10e-6 * (now.tv_usec - info->start.tv_usec))), nb);
	else if (act == 1)
		printf("%.0f %d is eating\n", ( 10e3 * ((now.tv_sec - info->start.tv_sec) + 10e-6 * (now.tv_usec - info->start.tv_usec))), nb);
	else if (act == 2)
		printf("%.0f %d is sleeping\n", ( 10e3 * ((now.tv_sec - info->start.tv_sec) + 10e-6 * (now.tv_usec - info->start.tv_usec))), nb);
	else if (act == 3)
		printf("%.0f %d is thinking\n", ( 10e3 * ((now.tv_sec - info->start.tv_sec) + 10e-6 * (now.tv_usec - info->start.tv_usec))), nb);
	else if (act == 4)
		printf("%.0f %d died\n", ( 10e3 * ((now.tv_sec - info->start.tv_sec) + 10e-6 * (now.tv_usec - info->start.tv_usec))), nb);
	pthread_mutex_unlock(&info->write);
}

void	routine_to_sleep_think(t_philo *philo)
{
	ft_write(philo->info, philo->num_philo, 2);
//	ft_usleep(philo->info->t_t_s, philo->info);
	ft_usleep(philo->info->t_t_s);
	//usleep(philo->info->t_t_s * 10^3);
	ft_write(philo->info, philo->num_philo, 3);
}

void	routine_to_eat(t_philo *philo)
{
	struct timeval	eat;
	pthread_mutex_lock(philo->l_f);
	pthread_mutex_lock(&philo->r_f);
	ft_write(philo->info, philo->num_philo, 0);
//	gettimeofday(&eat, NULL);
//	if (((10e3 * ((eat.tv_sec - philo->info->start.tv_sec) + 10e-6 * (eat.tv_usec - philo->info->start.tv_usec))) - philo->l_eat) > philo->info->t_t_d)
//	{
//		printf("%.0f\n", ((10e3 * ((eat.tv_sec - philo->info->start.tv_sec) + 10e-6 * (eat.tv_usec - philo->info->start.tv_usec))) - philo->l_eat));
//		ft_write(philo->info , philo->num_philo, 4);
//		philo->info->death = 1;
//		exit(1);
//	}
	ft_write(philo->info, philo->num_philo, 1);
	philo->eat++;
//	ft_usleep(philo->info->t_t_e, philo->info);
	ft_usleep(philo->info->t_t_e);
//	usleep(philo->info->t_t_e * 10^3);
	gettimeofday(&eat, NULL);
	philo->l_eat = ((10e3 * ((eat.tv_sec - philo->info->start.tv_sec) + 10e-6 * (eat.tv_usec - philo->info->start.tv_usec))) - philo->l_eat);
	pthread_mutex_unlock(&philo->r_f);
	pthread_mutex_unlock(philo->l_f);
	routine_to_sleep_think(philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	philo = (t_philo*)arg;

	if (philo->num_philo % 2 == 0)
		usleep(philo->info->nb_t_e / 10);
	if (philo->info->nb_t_e <= 0)
	{
		while (philo->info->death == 0)
			routine_to_eat(philo);
	}
	else if (philo->info->nb_t_e > 0)
	{
		while (philo->info->death == 0 && (philo->eat < philo->info->nb_t_e))
				routine_to_eat(philo);
	}
}