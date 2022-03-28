#include "../../include/philo.h"

int	lst_rmv(t_list *list, t_test *remove)
{
	t_test	*previous;

	if (list == NULL || remove == NULL)
		return (-1);
	if (remove == list->first)
		list->first = list->first->next;
	else
	{
		previous = list->first;
		while ((previous->next != remove) && (previous != NULL))
			previous = previous->next;
		if (previous == NULL)
			return (-1);
		previous->next = remove->next;
		if (previous->next == NULL)
			list->last = previous;
	}
	list->size--;
//	free(remove);
	return (0);
}