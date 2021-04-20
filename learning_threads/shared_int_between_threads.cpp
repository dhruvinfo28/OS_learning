#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

long long x = 0;

void * incrementer(void *arg){
    for(int i=0;i<1000000;i++){
        //So know this thread in critical section, and when it has the lock no other thread will be able to access this 
        pthread_mutex_lock(&lock);
        x++;
        pthread_mutex_unlock(&lock);
        //Leaves and unlocks
    }
    return NULL;
}

int main(){
    pthread_t id;
    pthread_create(&id, NULL, incrementer, NULL);
    for(int i=0;i<1000000;i++){
        pthread_mutex_lock(&lock);
        x++;
        pthread_mutex_unlock(&lock);
    }
    pthread_join(id,NULL);

    //One thing we will notice is that we get the wrong answer
    //Suppose child thread sees x as 10 , but main was incrementing it, so we end up incremeting by 1 , but should have incremented 
    //two
    //This is basically the race condition

    //To avoid it, we can use mutual exclusion , via lock in pthread library
    printf("%lld\n",x);


    //ALso we know that threads can be processed parallely but since here both the threads share a variable 1000000 times the processor actually processes them on one core, hence slowing down the process and completely destroying the benefits of threads
    //Hence know when to use threads
    return 0;
}