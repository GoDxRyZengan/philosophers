/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:35:13 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 04:37:19 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

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
		printf("case n°%u\n", list->size - i);
		printf("%i\n", current->i);
		printf("%i\n", current->j);
		putchar('\n');
		current = current->next;
	}
	printf("(null)\n");
	printf("\ncase : %u\n", list->size);
	return (0);
}
