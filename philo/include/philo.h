/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:50:58 by hucoulon          #+#    #+#             */
/*   Updated: 2022/04/13 18:51:01 by hucoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <ctype.h>

typedef struct s_info	t_info;

typedef struct s_philo
{
	int				num_philo;
	int				nb_eat;
	long int		l_eat;
	pthread_t		id;
	pthread_mutex_t	r_f;
	pthread_mutex_t	*l_f;
	t_info			*info;
}				t_philo;

struct s_info
{
	int				nb_philo;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				nb_t_e;
	int				death;
	long int		start;
	pthread_mutex_t	eat;
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
	t_philo			*philo;
};

int			check_arg(char **argv);
int			check_int(char	*str);
int			ft_strlen(char *str);
void		init_philo_utils(t_info *info, int i);
void		init_philo(t_info *info);
void		init_struct(char **tab, int argc, t_info *info);
void		*routine(void *arg);
void		routine_to_eat(t_philo *philo);
void		ft_usleep(long int time, t_philo *philo);
void		init_struct(char **tab, int argc, t_info *info);
long int	ft_atoi(const char *str);
long int	actual_time(void);
void		check_death(t_philo *philo);
int			check_stop(t_philo *philo);
void		ft_write(t_philo *philo, int nb, int act, char *str);
void		end_prog(t_philo *philo);

#endif
