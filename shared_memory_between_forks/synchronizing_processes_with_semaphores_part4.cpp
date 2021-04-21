#include<iostream>
#include<semaphore.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/wait.h>
using namespace std;

//Declaring the semaphore
sem_t s; 

int main(){
    int *shared_var = (int *)mmap(NULL, 4096, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *shared_var = 0;
    //Initializing semaphore: 
    //First is the pointer to the semaphore, second is number of processes you want to synchronize, if you want to synchronize
    //threads use 0
    //Next is the initializing value of the semaphore i.e. 1
    sem_init(&s,2,1);
    int pid = fork();
    if(pid==0){
        if(fork()==0){
            //Child 2
            for(int i=0;i<10;i++){
                sem_wait(&s);
                usleep(1);
                (*shared_var)++;
                sem_post(&s);
            }
        }
        else{
            //Child 1
            for(int i=0;i<10;i++){
                sem_wait(&s);
                (*shared_var)--;
                usleep(1);
                sem_post(&s);
            }

        }
    }
    else{
        wait(NULL);
        cout<<*shared_var<<endl;
    }

    return 0;
}