#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int pid=fork();
	char *s = (char *)malloc(10);
	if(pid==0){
		*s = 'd';
	 	printf("Child %p Value: %c\n",s,*s);
	}
	else{
		*s = 'p';
		printf("Parent %p Value: %c\n",s,*s);
	}
return 0;
}
