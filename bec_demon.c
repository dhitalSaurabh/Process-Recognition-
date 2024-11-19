// Program to create a demon process.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void create_daemon() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }
    if (chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }
    umask(0);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    openlog("mydaemon", LOG_PID | LOG_CONS, LOG_DAEMON);
    syslog(LOG_INFO, "Daemon started");
    while (1) {
        syslog(LOG_INFO, "Daemon is running...");
        sleep(10); 
    }
    closelog();
}

int main() {
    create_daemon();
    return EXIT_SUCCESS;
}
