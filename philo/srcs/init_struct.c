#include "../include/philo.h"

void	init_philo_utils(t_info *info, int i)
{
	pthread_mutex_init(&info->philo[i].r_f, NULL);
	if (i == info->nb_philo - 1)
		info->philo[i].l_f = &info->philo[0].r_f;
	else
		info->philo[i].l_f = &info->philo[i + 1].r_f;
	info->philo[i].num_philo = i + 1;
	info->philo[i].eat = 0;
	info->philo[i].l_eat = 0;
	info->philo[i].info = info;
}

int	init_philo(t_info *info)
{
	int i;
	
	i = 0;
	while (i < info->nb_philo)
	{
		init_philo_utils(info, i);
		i++;
	}
	i = 0;
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
	return (0);
}

void	init_struct(char **tab, int argc, t_info *info)
{
	pthread_mutex_init(&info->write, NULL);
	gettimeofday(&info->start, NULL);
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