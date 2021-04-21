#include<iostream>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/wait.h>

using namespace std;

int main(){
    int *shared_int = (int *)mmap(NULL,4096,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,-1,0);
    *shared_int = 0;
    pid_t pid = fork();
    if(pid==0){
        if(fork()==0){
            for(int i=0;i<10;i++){
                (*shared_int)--;
                usleep(1);
            }
        }else{
            wait(NULL);
            for(int i=0;i<10;i++){
                (*shared_int)++;
                usleep(1);
            }
        }
    }
    else{
        //Now this parent waits specifically for child 1 to terminate
        waitpid(pid,NULL,0);
        //If we used only wait, this process will wait until any of its process terminates, so if child2 finished first parent will start and we don't want that
        cout<<*shared_int<<endl;
    }
    return 0;
}