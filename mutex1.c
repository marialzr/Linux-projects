//Scrieti o aplicatie care creeaza N threaduri ce concureaza pt a citi cuvinte de la tastatura. 
//La fiecare citire, va fi afisat indexul threadului ce face citirea. Toate threadurile se vor termina dupa citirea a M cuvinte. 
//M si N se vor da ca parametri din linia de comanda. La final, threadul principal (main) va afisa pentru fiecare thread 
//toate cuvintele pe care le-a citit, in ordinea in care au fost citite.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
int m, a[100][100], ok;
pthread_mutex_t mtx;
void* function(void* arg)
{
	int id=*(int*)arg;
	int nr;
	while (1)
	{
		pthread_mutex_lock(&mtx);
		if (m==0)
		{
			pthread_mutex_unlock(&mtx);
			return NULL;
		}
		printf("Give the number:\n");
		scanf("%d", &nr);
		printf("%d %d\n", id, nr);
		a[id][nr]=1;
		m--;
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}
int main(int argc, char* argv[])
{
	pthread_t th[100];
	int n, i;
	n=atoi(argv[1]);
	m=atoi(argv[2]);
	for (i=0; i<n; i++)
	{
		int* nr=(int*)malloc(sizeof(int));
		*nr=i;
		pthread_create(&th[i], NULL, function, nr);
	}
	for (i=0; i<n; i++)
		pthread_join(th[i], NULL);
	for (i=0; i<n; i++)
	{
		printf("The thread with id equals to %d has read: ", i);
		for (int j=0; j<100; j++)
			if (a[i][j]==1)
				printf("%d ", j);
	}
	return 0;
}

