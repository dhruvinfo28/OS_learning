#include<iostream>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>

using namespace std;

int *shared;

void *function1(void *arg){ 
    int x;
    for(int i=0;i<10000;i++){
        x = *shared;
        x++;
        *shared = x;
        usleep(1);
    }
    return NULL;
}

void *function2(void *arg){ 
    int x;
    for(int i=0;i<10000;i++){
        usleep(1);
        x = *shared;
        x--;
        *shared = x;
    }
    return NULL;
}

int main(){
    shared = (int *)malloc(sizeof(int));
    *shared = 0;
    pthread_t thread_1, thread_2;

    pthread_create(&thread_1, NULL, function1,NULL);
    pthread_create(&thread_2,NULL,function2,NULL);
    pthread_join(thread_1,NULL);
    pthread_join(thread_2,NULL);

    cout<<*shared<<endl;
    return 0;
}