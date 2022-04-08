#include "../include/philo.h"
/*
void	ft_usleep(unsigned int time)
{
	struct timeval	start;
	struct timeval	now;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	while ((10e3 * ((now.tv_sec - start.tv_sec) + 10e-6 * (now.tv_usec - start.tv_usec))) < time)
	{
//		printf("%.0f\n", (10e3 * ((now.tv_sec - start.tv_sec) + 10e-6 * (now.tv_usec - start.tv_usec))));
		usleep(1000);
		gettimeofday(&now, NULL);
	}
//	printf("%.0f\n", (10e3 * ((now.tv_sec - start.tv_sec) + 10e-6 * (now.tv_usec - start.tv_usec))));
}*/


long int	actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

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