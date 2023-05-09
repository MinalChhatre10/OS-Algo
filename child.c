#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char *argv[]) {
printf("We are in child program\n");
printf("pid of child program = %d\n",getpid());
printf("Argument 1: %s\n", argv[1]);
printf("Argument 2: %s\n", argv[2]);
return 0;
}
