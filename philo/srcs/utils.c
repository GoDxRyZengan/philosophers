#include "../include/philo.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

long int	ft_atoi(const char *str)
{
	long int	a;
	long int	res;
	long int	neg;

	neg = 1;
	res = 0;
	a = 0;
	while (str[a] == ' ' || (str[a] > 6 && str[a] < 14))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			neg = -1;
		a++;
	}
	while (str[a] > 47 && str[a] < 58)
	{
		res = res * 10 + (str[a] - 48);
		a++;
	}
	return (res * neg);
}