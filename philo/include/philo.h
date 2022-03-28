#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>


typedef struct	s_philo
{
	int			num_philo;
	char		status;
	pthread_t	id;
}				t_philo;


typedef	struct s_info
{
	int		nb_philo;
	int		t_t_d;
	int		t_t_e;
	int		t_t_s;
	int		nb_t_e;
	t_philo	*philo;
}				t_info;

void	init_struct(char **tab, int argc, t_info *info);
long int	ft_atoi(const char *str);

#endif