#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_info info;

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
	if (init_philo(&info) == -1)
		return (0);
	return (0);
}