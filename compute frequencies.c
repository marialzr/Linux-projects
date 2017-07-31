#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//Sa se scrie un program care calculeaza si afiseaza frecventa caracterului 5 si a caracterului 7 in cuvintele primite ca 
//argumente in linia de comand. Programul va crea un numar de thread-uri egal cu numarul de argumente din linia de comanda.

int a, b;

pthread_mutex_t mtxa = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mtxb = PTHREAD_MUTEX_INITIALIZER;


void* f(void * p)
{
    char* sir = (char*)p;
    for ( int i = 0; sir[i]; i++)
    {
        if (sir[i] == '5')
        {
            pthread_mutex_lock(&mtxa);
            a++;
            pthread_mutex_unlock(&mtxa);   
        }
        if (sir[i] == '7')
        {
            pthread_mutex_lock(&mtxb);
            b++;
            pthread_mutex_unlock(&mtxb);
        }

    }
    return NULL;
}

int main(int argc, char** argv)
{
    int i;
    pthread_t * th;
    th = (pthread_t *)malloc(sizeof(pthread_t) * argc);
    for (i = 1; i < argc; i++)
    {
        pthread_create(th + i, NULL, f, (void *)argv[i]);
    }
    
    for (i = 0; i < argc; ++i )
        pthread_join(th[i], NULL);
    printf("a = %d\nb = %d\n", a, b);
    free(th);

    return 0;
}













