/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:33:00 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:33:02 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	lst_add(t_list *list, t_test *current, t_test *add)
{
	t_test	*tmp;

	if (list == NULL)
		return (-1);
	if (current == NULL)
	{
		add->next = list->first;
		list->first = add;
	}
	else
	{
		tmp = current->next;
		current->next = add;
		add->next = tmp;
	}
	if (add->next == NULL)
		list->last = add;
	list->size++;
	return (0);
}
