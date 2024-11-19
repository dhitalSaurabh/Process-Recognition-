#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */

/**
 * setup() reads in the next command line, separating it into distinct tokens
 * using whitespace as delimiters. It also sets the args parameter as a 
 * null-terminated string.
 */

void setup(char inputBuffer[], char *args[],int *background)
{
    int length, /* Number  of characters in the command line */
        i,      /* Loop index for inputBuffer array */
        start,  /* Index where beginning of next command parameter is */
        ct;     /* Index of where to place the next parameter into args[] */

    ct = 0;

    /* Read what the user enters on the command line */
    length = read(STDIN_FILENO, inputBuffer, MAX_LINE);  

    start = -1;
    if (length == 0)
        exit(0);            /* ^d was entered, end of user command stream */
    if (length < 0){
        perror("error reading command");
    exit(-1);           /* terminate with error code of -1 */
    }

    /* Examine every character in the inputBuffer */
    for (i = 0; i < length; i++) { 
        switch (inputBuffer[i]){
        case ' ':
        case '\t' :               /* argument separators */
            if(start != -1){
                args[ct] = &inputBuffer[start];    /* set up pointer */
                ct++;
            }
            inputBuffer[i] = '\0'; /* add a null char; make a C string */
            start = -1;
            break;

        case '\n':                 /* should be the final char examined */
            if (start != -1){
                args[ct] = &inputBuffer[start];     
                ct++;
            }
            inputBuffer[i] = '\0';
            args[ct] = NULL; /* no more arguments to this command */
            break;

        case '&':
            *background = 1;
            inputBuffer[i] = '\0';
            break;

        default :             /* some other character */
            if (start == -1)
                start = i;
    } 
    }    
    args[ct] = NULL; /* just in case the input line was > 80 */
} 

int main(void)
{
    char inputBuffer[MAX_LINE]; /* Buffer to hold the command entered */
    int background;             /* Equals 1 if a command is followed by '&' */
    char *args[MAX_LINE/2+1];/* Command line (of 80) has max of 40 arguments */


    while (1){            /* program terminates normally inside setup */
    background = 0;
    printf("CSE2431Sh->");
        fflush(0);
        setup(inputBuffer, args, &background);       /* get next command */

    /* the steps are:
     (1) fork a child process using fork()
     (2) the child process will invoke execvp()
     (3) if background == 0, the parent will wait, 
        otherwise returns to the setup() function. */

          /* MY CODE HERE */
          pid_t pid;

        pid = fork();

        if(pid == 0)
        {
                execvp(args[0],args);
                /* If execvp returns, it must have failed. */

                printf("Fork Failed\n");
                exit(0);
        }
        else
        {
                if(&background == 0)
                {
                        while( wait(&background) != pid)
                        {/* Do nothing, waiting */}
                }
                else
                {
                        setup(inputBuffer, args, &background);
                }
       }
   }
}