#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a process with a given name is running
int is_process_running(const char *process_name) {
    char command[256];
    snprintf(command, sizeof(command), "ps aux | grep '%s' | grep -v grep", process_name);

    FILE *fp;
    char buffer[1024];
    int process_found = 0;

    // Open a pipe to the command
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        return -1;
    }

    // Read the output of the command
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, process_name) != NULL) {
            process_found = 1;
            break;
        }
    }

    // Close the pipe
    pclose(fp);

    return process_found;
}

int main(int argc, char *argv[]) {
    // Ensure at least one argument is passed
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <process_name>\n", argv[0]);
        return 1;
    }

    const char *process_name = argv[1];
    int result = is_process_running(process_name);

    if (result == -1) {
        fprintf(stderr, "Error checking process.\n");
        return 1;
    }

    if (result) {
        printf("Process '%s' is running.\n", process_name);
    } else {
        printf("Process '%s' is not running.\n", process_name);
    }

    return 0;
}