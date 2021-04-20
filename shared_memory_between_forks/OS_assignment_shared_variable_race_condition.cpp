#include<iostream>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/wait.h>

#define PAGESIZE 4096

using namespace std;



int main(){
    int *shared_var = (int *)mmap(NULL,PAGESIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,-1,0);
    *shared_var = 0;
    int pid = fork();
    if(pid==0){
        //First child
        for(int i=0;i<10;i++){
            (*shared_var)++;
            usleep(1);
        }
        int pid2 = fork();
        if(pid2==0){
            //Second child
            for(int i=0;i<10;i++){
                (*shared_var)--;
                usleep(1);
            }
        }else{
            //first child
        }
    }else{
        //Parent, waiting for its child to terminate
        wait(NULL);
        cout<<*shared_var<<endl;
    }

    return 0;
}