#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char *argv[]) {
printf("pid of prent-program = %d\n",getpid());
char *args[] = {" hello","from", "child", NULL};
//arg[0]="forkChild.c";
//arg[1]="\nHello from ";
//arg[2]=" process 2";
execv("./child1",args);
printf("Back to parent program\n");
return 0;
}
