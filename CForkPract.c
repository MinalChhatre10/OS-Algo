#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argv,char* args[]){


printf("I am child process\n");
printf("My process id is %d\n",getpid());
printf("My parent process id is %d\n",getppid());

printf("argument2 :%s\n",args[1] );
printf("argument3 :%s\n",args[2] );
return 0;
}
