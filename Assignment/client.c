#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    mqd_t mq;
    char buffer[1024]; // buffer to hold message data

    //// Open message queue for writing
    mq = mq_open("/messageQueue", O_WRONLY);

    fflush(stdout);
    memset(buffer,0,1024);        // clear buffer  
    strcpy(buffer,argv[1]); // copy message from command-line argument to buffer
    mq_send(mq,buffer,1024,0);

    printf("%s", buffer);

    mq_close(mq); // close message queue

    return 0;

}