//Sa se scrie o aplicatie care creeaza N threaduri (N se transmite din linia de comanda), 
//care la pornire vor fi toate blocate. Dupa ce au fost create toate threadurile, 
//threadul principal il deblocheaza pe unul dintre ele (nu are importanta pe care). 
//Acel thread isi va afisa indexul, si va citi un numar de la tastatura intre 0 si N-1 
//(se valideaza inclusiv sa nu se introduca indexul unui thread deja introdus), 
//iar ulterior va debloca threadul al carui index a fost citit, dupa care threadul isi termina executia. 
//Programul continua pana cand se termina toate threadurile. Ultimul thread 
//(thread-ul cu numarul egal cu numarul dat de la tastatura) nu va mai efectua citirea.

Exemplu:
./test 8
Index thread:0
Give the number: 7
Index thread:7
Give the number: 1
Index thread:1
Give the number: 5
Index thread:5
Give the number: 6
Index thread:6
Give the number: 2
Index thread:2
Give the number: 3
Index thread:3
Give the number: 4
Index thread:3
Give the number: 8
//here the progtam ends

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
int n;
pthread_mutex_t mtx[100];
void* function(void*arg)
{
	int id=(int*)arg;
	pthread_mutex_lock(&mtx[id]);
	int nr;
	printf("Thread index: %d\n", id);
	printf("Give the number\n");
	scanf("%d", &nr);
	pthread_mutex_unlock(&mtx[nr]);
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t th[100];
	n=atoi(argv[1]);
	int i;
	for (i=0; i<n; i++)
		pthrdead_mutex_init(&mtx[i], NULL);
	for (i=0; i<n; i++)
	{
		pthread_mutex_lock(&mtx[i]);
		int* id=(int*)malloc(sizeof(int));
		*id=1;
		pthread_create(&th[i], NULL, function, id);
	}
	pthread_mutex_unlock(&mtx[0]);
	for (i=0; i<n; i++)
		pthread_join(th[i], NULL);
	return 0;
}
