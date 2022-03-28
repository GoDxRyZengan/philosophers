#include "../../include/philo.h"

t_list	*lst_new(void)
{
	t_list	*new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return (NULL);
	return (new);
}
