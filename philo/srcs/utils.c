#include "../include/philo.h"

/*
void	ft_usleep(unsigned int time, t_info *info)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	printf("TRY :%f\n", (10e3 * ((now.tv_sec - info->start.tv_sec) + 10e-6 * (now.tv_usec - info->start.tv_usec))));
	while ((10e3 * ((now.tv_sec - info->start.tv_sec) + 10e-6 * (now.tv_usec - info->start.tv_usec))) < time)
	{
//		printf("%.0f\n", (10e3 * ((now.tv_sec - start.tv_sec) + 10e-6 * (now.tv_usec - start.tv_usec))));
		usleep(1000);
	}
//	printf("%.0f\n", (10e3 * ((now.tv_sec - start.tv_sec) + 10e-6 * (now.tv_usec - start.tv_usec))));
}


long int	actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time_in_ms, t_info *info)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
//	printf("%ld\n", start_time);
	printf("DEBUT:%ld\n", actual_time());
	while ((actual_time() - start_time) < time_in_ms)
	{
//		printf("%ld\n", actual_time() - start_time);
		usleep(1000);
//		printf("%ld\n", actual_time() - start_time);
	}
	printf("FIN:  %ld\n", actual_time());
}
 
//le bon

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
	time_in_ms = time_in_ms * 10e-3;
	while ((actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}*/

long int	actual_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		return (-1);
//	gettimeofday(&current_time, NULL) == -1;
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	time_in_ms = time_in_ms * 10e-3;
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