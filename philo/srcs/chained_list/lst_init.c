#include "../../include/philo.h"

t_list	*lst_init(t_philo *init)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	init->next = NULL;
	list->size = 1;
	list->first = init;
	list->last = init;
	return (list);
}