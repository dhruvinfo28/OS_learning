#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
void *myFunc(void *args){
	int *x = args;
	printf("New thread %d\n",*x);
	return NULL;
}
int main(){
	int *x = (int *)malloc(sizeof(int));
	*x = 100;
	pthread_t thread_id;
	pthread_create(&thread_id,NULL,myFunc,x);
	pthread_join(thread_id,NULL);
	return 0;
}
