//Scrieti o aplicatie care creeaza N threaduri ce concureaza pt a citi numere de la tastatura. 
//La fiecare citire, va fi afisat indexul threadului ce face citirea. Toate threadurile se vor termina 
//dupa citirea a M numere. M si N se vor da ca parametri din linia de comanda. La final, threadul principal 
//(main) va afisa pentru fiecare thread toate numerele pe care le-a citit, in ordine crescatoare.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
int m;
char v[100][100];
pthread_mutex_t mtx;
void* function(void* arg)
{
	int id=*(int*)arg;
	char word[100];
	while (1)
	{
		pthread_mutex_lock(&mtx);
		if (m==0)
		{
			pthread_mutex_unlock(&mtx);
			return NULL;
		}
		printf("Id thread: %d\n", id);
		printf("Give the word: \n", id);
		scanf("%d", word);
		m--
		strcat(v[id], " ");
		strcat(v[id], word);
		printf("%s", v[id]);
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}
int main(int argc, char* argv[])
{
	pthread_t th[100];
	int n=atoi(argv[1]);
	m=atoi(argv[2]);
	for (i=0; i<n; i++)
	{
		int* nr=(int*)malloc(sizeof(int));
		*nr=i;
		pthread_create(&th[i], NULL, function, nr);
	}
	for (int i=0; i<n; i++)
		pthread_join(th[i], NULL);
	for (int i=0; i<n; i++)
	{
		printf("The thread with id equals to %d has read: %s ", i, v[i]);
	}
	return 0;
}
