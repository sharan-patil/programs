#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>

#define MAXLINE 80 /* The maximum length of a command line */
#define MAXARGS 40 /* The maximum # of tokens in command line */

int main(void)
{
    char cmdline[MAXLINE];
    char *args[MAXARGS];
    int i = 0;
    int ampersandFlag;
    int fd;
    const int SIZE = 4096;
    const char *name = "OS";
    const char *message = "heelo";
    long int *ptr;
    
    printf("CS149 Fall 2020 Shellipc from Sharan Basavaraj Patil\n");
    while (1) {
        ampersandFlag = 0;
        printf("Sharan-489>");
        fflush(stdout);
 
        fgets(cmdline, MAXLINE, stdin);
        strtok(cmdline, "\n");
        char *token = strtok(cmdline, " ");
        
        for (i = 0; token != NULL; i++)
        {
            args[i] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
        if (strcmp(args[0], "exit") == 0)
        {
            exit(0) ;
        }
        if (strcmp(args[i - 1], "&") == 0)
        {
            ampersandFlag = 1;
            args[i - 1] = NULL;
        }
        int pid = fork();
        if (pid != 0)
        {
            if (ampersandFlag == 0)
            {
                wait(0);
                struct timeval current;
                gettimeofday(&current, NULL);
                fd = shm_open(name, O_RDONLY, 0666);
                ptr = (long *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
                printf("(elapsed time: %ld.%06ld)", current.tv_sec - ptr[0], current.tv_usec);
                shm_unlink(name);
            }
        }
        else
        {
            if (ampersandFlag == 0)
            {
                struct timeval current;
                gettimeofday(&current, NULL);
                fd = shm_open(name, O_CREAT | O_RDWR, 0666);
                ftruncate(fd, SIZE);
                ptr = (long *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
                ptr[0] = current.tv_sec;
                ptr[1] = current.tv_usec;
            }
            int ret = execvp(args[0], args);
            if (ret == -1)
                printf("Error\n");
        }
    }
    
 return 0;
}
