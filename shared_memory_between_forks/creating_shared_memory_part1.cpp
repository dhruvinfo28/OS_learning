#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/wait.h>

#define PAGESIZE 4096


//For a child process , the stack and heap are copied to a new place in memory threrefore has its own address space.
//Refer fork for details
int main(){
    int *unshared_mem = (int *)malloc(sizeof(int));
    *unshared_mem = 78;
    //The first argument is the starting address of the memory, if we pass NULL kernel automatically allocates from any address
    //This creates a shared memory between parent and the child process
    //We have read and write permissions on the memory PROT_WRITE PROT_READ
    //Memory is shared and is anonymous that is it can only be shared by parent and its child processes
    int *shared_mem = (int *)mmap(NULL,PAGESIZE, 
                                PROT_WRITE | PROT_READ,
                                MAP_SHARED|MAP_ANONYMOUS,-1,0);
    *shared_mem = 10;
    int pid = fork();
    if(pid==0){
        *unshared_mem = 1;
        *shared_mem = 20;
        printf("Child changed the shared memory\n");
    }else{
        //The parent process waits for the child to terminate
        wait(NULL);
        printf("Changes parent didn't see: %d\n",*unshared_mem);
        printf("Parent saw the changes: %d\n",*shared_mem);
    }
    return 0;
}
