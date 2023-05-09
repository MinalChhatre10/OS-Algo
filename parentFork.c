#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Error occurred while forking
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        char* args[] = {"./child", "argument1", "argument2", NULL};
        execv("./child", args);
        // execv only returns if an error occurs
        fprintf(stderr, "Execv failed\n");
        return 1;
    } else {
        // Parent process
        printf("We are in parent program\n");
        printf("pid of parent program = %d\n", getpid());
          printf("ppid of child program = %d\n", getppid());

        // Wait for the child process to complete
        wait(NULL);

        printf("Child process complete\n");
        return 0;
    }
}
