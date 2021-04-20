#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *function(void *arg){
	pthread_detach(pthread_self());
	printf("This is the result of a detached thread");
	pthread_exit(NULL);
}

int main(){
	pthread_t  thread;
	pthread_create(&thread,NULL,function,NULL);
	pthread_join(thread,NULL);
	return 0;
}
