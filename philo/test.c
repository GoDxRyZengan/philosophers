#include <stdio.h>
#include <sys/time.h>

//	now.tv_sec : seconde
//	now.tv_usec : microseconde
//	milliseconde 1 000 = seconde 1 : valeur demander
//	microseconde 1 000 000 = seconde 1
int	main()
{
	struct timeval now;
	struct timeval later;
	
	gettimeofday(&now, NULL);
	printf("nb de seconde : %ld\nnb de millisaconde %ld\n", now.tv_sec, now.tv_usec);
	gettimeofday(&later, NULL);
	printf("%f en seconde\n", (later.tv_sec - now.tv_sec) + 10e-6 * (later.tv_usec - now.tv_usec));
	printf("%.3f en milliseconde\n", (later.tv_sec - now.tv_sec) + 10e-6 * (later.tv_usec - now.tv_usec));
	printf("DEBUT :%ld\n", (now.tv_sec + (now.tv_usec * 10^-6)));
	printf("FIN   :%ld\n", (later.tv_sec + (later.tv_usec * 10^-6)));
	return 0;
}