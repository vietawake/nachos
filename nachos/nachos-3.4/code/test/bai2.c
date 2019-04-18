#include <pthread.h>
#include <stdio.h>

void *ProcessP1(void *arg)
{
	sleep(1);
	printf("A1\n");
	sleep(1);
	printf("A2\n");
	return NULL;
}

void *ProcessP2(void *arg)
{
	sleep(1);
	printf("B1\n");
	sleep(1);
	printf("B2\n");
	
	return NULL;
}

int main()
{
	pthread_t pth1, pth2;

	
	pthread_create(&pth1,NULL,ProcessP1,NULL);
	pthread_create(&pth2,NULL,ProcessP2,NULL);
	
	pthread_join(pth2,NULL);
	pthread_join(pth1,NULL);
	
	return 0;
}
