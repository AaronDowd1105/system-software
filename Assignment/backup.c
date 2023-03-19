#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid = fork(); // Create a new process by forking the current process

    char *cmdrsync = "rsync"; // Create a string to store the command "rsync"
    char *args1[]={cmdrsync, "-avrt", "--delete", "/var/www/c15410232.com/html/dev/.", "/var/www/c15410232.com/html/live/", NULL};

    if(pid == -1){
        perror("Error: creating fork in rsync.h"); // Check if the fork failed
    }

    else if(pid == 0) // If the fork was successful and this is the child process
    {
        execvp(cmdrsync, args1); // Replace the current process with the rsync command
        exit(1);
    }
    return 0;
}
