#include "../../include/philo.h"

int	lst_add(t_list *list, t_philo *current, t_philo *add)
{
	t_philo	*next;

	if (list == NULL)
		return (-1);
	if (befor == NULL)
	{
		add->next = list->first;
		list->first = add;
	}
	else
	{
		next = befor->next;
		befor->next = add;
		add->next = after;
	}
	if (add->next == NULL)
		list->last = add;
	list->size++;
	return (0);
}