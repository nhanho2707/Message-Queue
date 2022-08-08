
#include "define.h"

struct msg message;

int main(int argc, char const *argv[])
{
    int consock;
    struct sockaddr_in serveraddress;

    int len;
    int waittime = 20;
    /* create message queue 1*/
    key_t key;
    int msgid;

    key = ftok(PathName, ProjectID1);
    msgid = msgget(key, 0666 | IPC_CREAT);

    /* connect to netdserver */
    consock = socket(AF_INET, SOCK_STREAM, 0);
    if(consock < 0)
    {
        fprintf(stderr,  "netdclient-socket() error !\n");
        exit(1);
    }

    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddress.sin_port = htons(PORTSRV2);
    bzero(&serveraddress.sin_zero, 8);

    if(connect(consock, (struct sockaddr*)& serveraddress, sizeof(serveraddress)) < 0)
    {
        fprintf(stderr, "netdclient-connect() error!\n");
        exit(1);
    }
    else
    {
        printf("Connected\n");
    }

    do
    {   
        /* read data from messsage queue */
        bzero(&message.mgs, BUFFER);
        msgrcv(msgid, &message,sizeof(message), 1, 0);
        printf("Data read from message queue 1: %s\n", message.mgs);

        /* send to netdserver */
        send(consock, message.mgs, BUFFER, 0);
        
    } while (strcmp(message.mgs, "bye") != 0);
    
    msgctl(msgid, IPC_RMID, NULL); 
   
    close(consock);
    return 0;
}
