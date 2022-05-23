#include "philo.h" 

int mails = 0;
pthread_mutex_t mutex;


void*	routine()
{
	for (int i = 0; i < 100; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int	main(int ac, char** ag)
{
	pthread_t th[4];
	int	i;

	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i <= 4; i++)
	{
		pthread_create(&th[i], NULL, &routine, NULL);
		printf("Thread %d has started \n", i);
	}
	for (i = 0; i <= 4; i++)
	{
		pthread_join(&th[i], (void **) NULL);
		printf("Thread %d has ended \n", i);
	}

	printf("mails = %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}
