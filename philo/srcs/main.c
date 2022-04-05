#include "../include/philo.h"

void	init_philo_utils(t_info *info, int i)
{
	info->philo[i].num_philo = i + 1;
	info->philo[i].fork = 1;
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
		printf("le philo %d est creer\n", info->philo[i].num_philo);
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		write(1, "lancement\n", 10);
//		printf("le philo n %d est lancer dans routine\n", info->philo[i].num_philo);
		pthread_create(&info->philo[i].id, NULL, &routine, &info->philo[i]);
		i++;
	}
	return (0);
}

void	init_struct(char **tab, int argc, t_info *info)
{
	info->nb_philo = ft_atoi(tab[1]);
	info->t_t_d = ft_atoi(tab[2]);
	info->t_t_e = ft_atoi(tab[3]);
	info->t_t_s = ft_atoi(tab[4]);
	if (argc == 6)
		info->nb_t_e = ft_atoi(tab[5]);
	else
		info->nb_t_e = -1;
}

int	main(int argc, char **argv)
{
	t_info info;
//	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		printf("ARG ERROR\n");// a enlever
		return (0);
	}
	if ((check_arg(argv)) == -1)
	{
		printf("ARGUMENT ERROR\n"); // a enlever
		return (0);
	}
	init_struct(argv, argc, &info);
	info.philo = malloc(sizeof(t_philo) * (info.nb_philo + 1));
	if (!info.philo)
		return (0);
//	info.philo = philo;
	if (init_philo(&info) == -1)
		return (0);
	return (0);
}