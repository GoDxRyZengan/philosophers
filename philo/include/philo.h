#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

typedef	struct	s_info	t_info;

typedef struct	s_philo
{
	int				num_philo;
	int				fork;
	pthread_t		id;
	t_info			*info;
}				t_philo;


typedef	struct s_info
{
	int				nb_philo;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				nb_t_e;
	t_philo			*philo;
}				t_info;

int		check_arg(char **argv);
int		check_int(char	*str);
int		ft_strlen(char *str);
void	*routine(void *arg);
void	init_struct(char **tab, int argc, t_info *info);
long int	ft_atoi(const char *str);

#endif