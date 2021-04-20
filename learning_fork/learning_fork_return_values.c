#include<stdio.h>
#include<unistd.h>
int main(){
	int id = fork();
	if(id==0){
		printf("Hello from child process\n");
	}
	else if(id<0){
		printf("Child process  creation failed\n");
	}
	else{
		printf("Parent process, Child ID:  %d\n", id);
	}
return 0;
}
