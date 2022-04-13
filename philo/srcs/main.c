#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->nb_philo == 1)
	{
		ft_usleep(philo->info->t_t_d, philo);
		ft_write(philo->info, philo->num_philo, 4);
		exit(0);
	}
	if (philo->num_philo % 2 == 0)
		usleep(philo->info->nb_t_e / 10);
	if (philo->info->nb_t_e <= 0)
	{
		while (philo->info->death == 0)
			routine_to_eat(philo);
	}
	else if (philo->info->nb_t_e > 0)
	{
		while (philo->info->death == 0 && (philo->nb_eat < philo->info->nb_t_e))
			routine_to_eat(philo);
	}
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
	if (init_philo(&info) == -1)
		return (0);
	free(info.philo);
	return (0);
}
