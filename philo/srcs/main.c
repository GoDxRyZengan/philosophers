#include "../include/philo.h"

void	*routine(void *arg)
{
	static int i = 0;
//	static pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
	t_philo	*philo;
	philo = (t_philo*)arg;
	printf("On est dans le thread n : %d // test %d\n", philo->num_philo, philo->info->nb_philo);
	i++;
//	pthread_exit(NULL);
	if (i == philo->info->nb_philo)
	{
		philo->info->
	}
}

int	init_philo_utils(t_info *info, int i)
{
	t_philo philo;
	int res;

	philo.num_philo = i + 1;
	philo.status = 'c';
	philo.info = info;
	res = pthread_create(&info->philo->id, NULL, &routine, &philo);
	if (res != 0)
		return (-1);
	pthread_join(info->philo->id, NULL);
	info->philo[i] = philo;
	return (0);
}


int	init_philo(t_info *info)
{
	int i;

	i = 0;
	while (i < info->nb_philo)
	{
		printf("%d\n", i);
		if (init_philo_utils(info, i) == -1)
			return (-1);
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
	t_philo	*philo;

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
	philo = malloc(sizeof(t_philo*) * (info.nb_philo + 1));
	if (!philo)
		return (0);
	info.philo = philo;
	if (init_philo(&info) == -1)
		return (0);
	return (0);
}