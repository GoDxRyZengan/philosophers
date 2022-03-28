#include "../include/philo.h"

void	*routine(void *arg)
{
	char	*status = (char *)arg;
	status = "Thread";
	pthread_exit(NULL);
}

int	main(int argc, char **argv)
{
//	t_info info;
//	int	i;
	char	*status;
	status = "Main";
	pthread_t philo1;

//	i = 0;
	if (argc < 5)
		return (0);
//	init_struct(argv, argc, &info);
//	while (i < info.nb_philo)
//	{
//		pthread_create(&philo1, NULL, &info, NULL);
//	}
//	info.status = "Main";
	printf("%s\n", status);
	pthread_create(&philo1, NULL, &routine, &status);
	pthread_join(philo1, NULL);
	printf("%s\n", status);
	return (0);
}
	//gerer le probleme de ft_atoi souligner par le correcteur de la derniere fois !!
