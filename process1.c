#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sched.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sleep(1);
        printf("CHILD: Child process exiting...\n");
        return 0;
    }

    // Parent process
    printf("PARENT: Waiting for child process...\n");
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        printf("PARENT: Child process exited with return code %d!\n",
               WEXITSTATUS(status));
    } else {
        printf("PARENT: Child process terminated abnormally!\n");
    }
    return 0;
}