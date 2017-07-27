//Implement a program that gets as arguments a file name followed by words. For each word, create a separate thread that counts 
//its appearances in a given file. Print out the sum of the appearances of all words.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#define N 100

pthread_mutex_t m;
int sum;
char* fn;

void* func(void* ar)
{
	FILE* pt;
	int number;
	char cmd[N], result[N];
	char* arg=(void*)ar;
	
	//we get the number of appearances of the current word from the file in "result"
	sprintf(cmd, "grep -o '\\<%s\\>' %s | wc -w", arg, fn);
	pt=popen(cmd, "r");
	fgets(result, 20, pt);
	pclose(pt);
	
	//convert "result" from char to int
	number=atoi(result);
	pthread_mutex_lock(&m);
	//add to the global variable that counts the sum of appearances
		sum=sum+number;
	pthread_mutex_unlock(&m);
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t t[N];
	int i;
	fn=argv[1];
	//create threads
	for(i=2; i<argc; i++)
		pthread_create(&t[i], NULL, func, argv[i]);
	
	for (i=2; i<argc; i++)
		pthread_join(t[i], NULL);
	printf("The sum is: %d\n", sum);
	return 0;
}
