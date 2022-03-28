/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunovill <lunovill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:25:23 by lunovill          #+#    #+#             */
/*   Updated: 2021/04/28 01:31:32 by lunovill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_test	t_test;
struct			s_test
{
	int i;
	int j;
	t_test	*next;
};

typedef	struct	s_list
{
	t_test	*first;
	t_test	*last;
	int	size;
}				t_list;

t_test			*lst_new();
t_list			*lst_init(t_test *init);
int				lst_add(t_list *list, t_test *befor, t_test *add);
int				lst_rmv(t_list *list, t_test *remove);
int				lst_print(t_list *list);

#endif
