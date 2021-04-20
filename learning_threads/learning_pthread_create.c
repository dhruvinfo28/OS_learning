#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *myFunc(void *vargp){
	sleep(1);
	printf("Printing from a new thread");
	return NULL;
}
int main(){
	pthread_t threadId;
	pthread_create(&threadId,NULL,myFunc,NULL);
	pthread_join(threadId,NULL);
return 0;
}
