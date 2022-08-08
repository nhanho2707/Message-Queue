

#include "define.h"

struct msg message;

int main(int argc, char const *argv[])
{
    /* create message queue 1*/
    key_t key;
    int msgid;

    key = ftok(PathName, ProjectID2);
    msgid = msgget(key, 0666 | IPC_CREAT);

    do
    {   
        /* read data from messsage queue */
        bzero(&message.mgs, BUFFER);
        msgrcv(msgid, &message,sizeof(message), 1, 0);
        printf("Data read from message queue 2: %s\n", message.mgs);
        
    } while (strcmp(message.mgs, "bye") != 0);

    msgctl(msgid, IPC_RMID, NULL); 
    return 0;
}
