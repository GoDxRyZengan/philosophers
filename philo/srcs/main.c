#include "../include/philo.h"


int		check_arg(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (check_int(argv[i]) == -1)
			return (-1);
		if 
	}
}

int	main(int argc, char **argv)
{
	t_info info;

	if (argc != 5 || argc != 6)
		return (0);
	if (check_arg(argv) == -1);
		return (0);
	info.philo = malloc(sizeof(t_philo) * (info.nb_philo + 1));
	if (!info.philo)
		return (0);
	init_philo(&info);
	return (0);
}
	//gerer le probleme de ft_atoi souligner par le correcteur de la derniere fois !!
