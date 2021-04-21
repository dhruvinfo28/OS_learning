#include<iostream>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>
#include<semaphore.h>

using namespace std;

int *shared;
//Semaphore declaration
sem_t s;

void *function1(void *arg){ 
    int x;
    for(int i=0;i<10000;i++){
        sem_wait(&s);
        x = *shared;
        x++;
        *shared = x;
        usleep(1);
        sem_post(&s);
    }
    return NULL;
}

void *function2(void *arg){ 
    int x;
    for(int i=0;i<10000;i++){
        sem_wait(&s);
        x = *shared;
        x--;
        *shared = x;
        usleep(1);
        sem_post(&s);
    }
    return NULL;
}

int main(){
    shared = (int *)malloc(sizeof(int));
    *shared = 0;
    //Initializing semaphore, refer process synchronization using semaphores in shared_memory_between_processes
    sem_init(&s,0,1);

    pthread_t thread_1, thread_2;

    pthread_create(&thread_1, NULL, function1,NULL);
    pthread_create(&thread_2,NULL,function2,NULL);
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);

    cout<<*shared<<endl;
    return 0;
}