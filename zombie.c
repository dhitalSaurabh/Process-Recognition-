// Program to demonstrate a process becoming zombie process. 
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{ 
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <sleep_duration>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the argument to an integer
    int sleep_duration = atoi(argv[1]);
    if (sleep_duration <= 0) {
        fprintf(stderr, "Please provide a positive integer for sleep duration.\n");
        return EXIT_FAILURE;
    }

    // Fork returns process id in parent process 
    pid_t child_pid = fork(); 
  
    // Parent process  
    if (child_pid > 0) {
        printf("Parent process (PID: %d) sleeping for %d seconds...\n", getpid(), sleep_duration);
        sleep(sleep_duration); 
        printf("Parent process (PID: %d) finished sleeping.\n", getpid());
    } 
  
    // Child process 
    else if (child_pid == 0) {
        printf("Child process (PID: %d) exiting...\n", getpid());
        exit(0); 
    } 
  
    // Error handling for fork failure
    else {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS; 
}
