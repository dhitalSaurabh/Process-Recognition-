// Program to create a process and to find the proess id.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_PATH 256
#define BUFFER_SIZE 1024

pid_t find_process_pid(const char *process_name)
{
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH];
    FILE *fp;
    char buffer[BUFFER_SIZE];

    if ((dir = opendir("/proc")) == NULL)
    {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0)
        {
            snprintf(path, sizeof(path), "/proc/%s/cmdline", entry->d_name);
            fp = fopen(path, "r");
            if (fp)
            {
                fgets(buffer, sizeof(buffer), fp);
                fclose(fp);

                if (strstr(buffer, process_name) != NULL)
                {
                    closedir(dir);
                    return atoi(entry->d_name);
                }
            }
        }
    }

    closedir(dir);
    return -1; // Process not found
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <process_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *process_name = argv[1];
    pid_t pid = find_process_pid(process_name);

    if (pid != -1)
    {
        printf("Process '%s' is running with PID: %d\n", process_name, pid);
    }
    else
    {
        printf("Process '%s' is not running.\n", process_name);
    }

    return EXIT_SUCCESS;
}
