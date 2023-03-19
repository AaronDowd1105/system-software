#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void main(void)
{
    char *cmdcp = "sh"; // declare command and arguments for sh

    char *args[]={"sh", "C:/Users/sdowd/Desktop/SystemSoftwareAssignment/bash_code/lock.sh", NULL};

    int pid = fork(); // create a new process using fork

    if(pid == -1) // check if fork was unsuccessful
    {
        perror("Error: creating fork in lockpermissions.h");
    }
    else if(pid == 0) // child process created successfully
    {
        execvp(cmdcp, args); // execute the command using execvp and exit
        exit(1);
    }
}