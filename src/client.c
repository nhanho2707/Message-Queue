

#include "define.h"

int main(int argc, char const *argv[])
{
    int consock;
    struct sockaddr_in serveraddress;

    int len;
    int waittime = 10;
    char sendmess[BUFFER], recvmess[BUFFER];


    consock = socket(AF_INET, SOCK_STREAM, 0);
    if(consock < 0)
    {
        fprintf(stderr, "client - socket() error !!\n");
        exit(1);
    }

    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddress.sin_port = htons(PORTSRV1);
    bzero(&serveraddress.sin_zero, 8);

    if(connect(consock, (struct sockaddr*)&serveraddress, sizeof(serveraddress)) < 0) 
    {
        fprintf(stderr, "client-connect() error!\n");
        exit(1);
    }
    else
    {
        printf("Connected\n");
    }

    do
    {
        printf("Enter mess: ");
        fgets(sendmess, BUFFER, stdin);
        len = strlen(sendmess);
        sendmess[len - 1] = '\0';
        send(consock, sendmess, BUFFER, 0);

        wait(&waittime);

        recv(consock, recvmess, BUFFER, 0);

        printf("Receive from server1: %s\n", recvmess);
    } while (strcmp(sendmess, "Goodbye") != 0);
    
    close(consock);
    return 0;
}
