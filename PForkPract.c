#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

pid_t pid = fork();

if(pid<0){
  //error
  printf("error occurred");
  exit(0);
}
else if(pid==0){
  //child process
  char *args[] = {"Child","Hello","World",NULL};
  execv("./childprocess",args);
}
else
{
  //parent process

  printf("wait till child process complete" );
  wait(NULL);
  printf("child process completed\n" );
  printf("I am parent process\n");
  printf("My process id is %d\n",getpid());
  printf("My parent process id is %d\n",getppid());


}

return 0;


}
