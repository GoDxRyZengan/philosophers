#include "../../include/philo.h"

int	lst_print(t_list *list)
{
	unsigned int	i;
	t_test			*current;

	if (list == NULL)
		return (-1);
	current = list->first;
	i = list->size;
	while ((current != NULL) && i--)
	{
		ft_printf("case nÂ°%u\n", list->size - i);
		ft_printf("%i\n", current->i);
		ft_printf("%i\n", current->j);
		ft_putchar('\n');
		current = current->next;
	}
	ft_putstr("(null)\n");
	ft_printf("\ncase : %u\n", list->size);
	return (0);
}