#include "../include/philo.h"

int		check_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
			i++;
		else
			return (-1);
	}
	i = 0;
	if (((ft_atoi(str)) < 0) || ((ft_atoi(str)) > 2147483647))
		return (-1);
	return (0);
}

int		check_arg(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (check_int(argv[i]) == -1)
			return (-1);
		i++; 
	}
	if (ft_atoi(argv[1]) < 1)
		return (-1);
	return (0);
}