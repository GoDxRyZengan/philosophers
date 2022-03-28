#include "../include/philo.h"

void	init_struct(char **tab, int argc, t_info *info)
{
	info->nb_philo = ft_atoi(tab[1]);
	info->t_t_d = ft_atoi(tab[2]);
	info->t_t_e = ft_atoi(tab[3]);
	info->t_t_s = ft_atoi(tab[4]);
	if (argc == 6)
		info->nb_t_e = ft_atoi(tab[5]);
	else
		info->nb_t_e = -1;
}