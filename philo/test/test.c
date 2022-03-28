#include "./list.h"

/*
void	*routine(void *arg)
{
	char *str;
	str = (char*)arg;
	printf("%s\n", str);
	str = "okkk";
	printf("%s\n", str);
	pthread_exit(NULL);
}

int	main(void)
{
	char	*status;

	status = malloc(sizeof(char) * 10);
	status = "Main";
	pthread_t philo1;
	printf("%s\n", status);
	pthread_create(&philo1, NULL, routine, status);
	pthread_join(philo1, NULL);
	printf("%s\n", status);
	return (0);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_1(void *arg) {
	char *i = (char *) arg;
	(*i) = 'a';
	// Arrêt propre du thread
	pthread_exit(NULL);
}

int main(void) {
	// Création de la variable qui va contenir le thread
	char i = '1';
	pthread_t thread1;
	printf("Avant la création du thread, i = %c.\n", i);
	// Création du thread
	pthread_create(&thread1, NULL, thread_1, &i);
	pthread_join(thread1, NULL);
	printf("Après la création du thread, i = %c.\n", i);
	return EXIT_SUCCESS;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef	struct	s_test
{
	char	*str;
}				t_test;


void *thread_1(void *arg) {
	t_test ok = (t_test) arg;
	ok->str = "Bon";
	pthread_exit(NULL);
}

int main(void) {
	t_test test;
	test.str = "Main";
	pthread_t thread1;
	printf("Avant la création du thread, i = %s.\n", test.str);
	pthread_create(&thread1, NULL, thread_1, &test);
	pthread_join(thread1, NULL);
	printf("Après la création du thread, i = %s.\n", test.str);
	return EXIT_SUCCESS;
}*

void	*test(char *str)
{

}

int		main(void)
{
	char	*str;
	str = "Bonjour";
	pthread_t philo;

	pthread_create(&philo, NULL, test, str);
	return (0);
}*/

int		main(void)
{
	int philo = 5;
	int i = 0;
	int j = 0;
	int k = 0;


	t_list *list;

	list = NULL;
	list = lst_init(lst_new());
	list->first->i = i;
	list->first->j = j;
	i++;
	j++;
	lst_add(list, list->first, lst_new());
	list->first->next->i = i;
	list->first->next->j = j;
	i++;
	j++;
	lst_add(list, list->first, lst_new());
	list->first->next->i = i;
	list->first->next->j = j;
	i++;
	j++;
	lst_add(list, list->first, lst_new());
	list->first->next->i = i;
	list->first->next->j = j;
	i++;
	j++;
	lst_add(list, list->first, lst_new());
	list->first->next->i = i;
	list->first->next->j = j;
	i++;
	j++;
//	while (k < philo);
//	{
//		lst_add(list, list->first, lst_new());
//		lst_print(list);
//		k++;
//	}
	lst_print(list);
	return (0);
}