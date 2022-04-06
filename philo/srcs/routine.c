#include "../include/philo.h"

void	ft_write(int nb, int act)
{
	pthread_mutex_t write;

	pthread_mutex_lock(&write);
	if (act == 0)
		printf("%d has taken a fork\n", nb);
	if (act == 1)
		printf("%d is eating\n", nb);
	if (act == 2)
		printf("%d is sleeping\n", nb);
	if (act == 3)
		printf("%d is thinking\n", nb);
	if (act == 4)
		printf("%d is dead\n", nb);
	pthread_mutex_unlock(&write);
}

void	routine_to_sleep(t_info *info, int nb)
{
	int i;

	i = 0;
	write(1, "OK\n", 3);
//	printf("philo n %d dans routine_to_sleep\n", nb);
	while (1)
		i++;
}

void	routine_to_eat(t_info *info, int nb)
{
	pthread_mutex_t fork;

//	pthread_mutex_init(&fork, NULL);
//	printf("philo n %d dans routine_to_eat\n", nb);
//	pthread_mutex_lock(&fork);
	if (info->philo[nb].fork == 1)
	{
//		pthread_mutex_lock(&fork);
		if ((nb == info->nb_philo - 1) && (info->philo[0].fork == 1))
		{
			pthread_mutex_lock(&fork);
			info->philo[nb].fork = 2;
			ft_write(nb, 0);
			info->philo[0].fork = 0;
			ft_write(nb, 1);
			info->philo[nb].fork = 1;
			info->philo[0].fork = 1;
			pthread_mutex_unlock(&fork);
		}
		else if (info->philo[nb + 1].fork == 1)
		{
			pthread_mutex_lock(&fork);
			info->philo[nb].fork = 2;
			ft_write(nb, 0);
			info->philo[nb + 1].fork = 0;
			ft_write(nb, 1);
			info->philo[nb].fork = 1;
			info->philo[nb + 1].fork = 1;
			pthread_mutex_unlock(&fork);
		}
//		pthread_mutex_unlock(&fork);
	}
	write(1, "LOL\n", 4);
//	pthread_mutex_destroy(&fork);
//	pthread_mutex_unlock(&fork);
	routine_to_sleep(info, nb);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	philo = (t_philo*)arg;

//	printf("le philo n:%d est dans la routine\n", philo->num_philo);
	routine_to_eat(philo->info, philo->num_philo);
}
