#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
void* my_function(void *arg){
    int *counter = (int *)arg;
    int *v = (int *)malloc(sizeof(int));
    *v = 5;
    while(*counter>0){
        printf("From the thread(The value you passed): %d\n", *counter);
        (*v)++;
        (*counter)--;
    }
    return (void *)v;
}

int main(){
    pthread_t thread_id;
    int *x = (int *)malloc(sizeof(int));
    *x = 3;
    pthread_create(&thread_id,NULL,my_function,(void *)x);

    int *return_val_from_thread;
    //Pointer to a pointer 
    pthread_join(thread_id,(void *)&return_val_from_thread);

    printf("Value from the thread: %d\n",*return_val_from_thread);

    return 0;
}