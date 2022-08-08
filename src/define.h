#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <netinet/in.h>

#define     PORTSRV1    8081
#define     PORTSRV2    8082
#define     BUFFER      100
#define     LISQUEUE    5

#define     MAX         10
#define     ProjectID1   123
#define     PathName    "define.h"
#define     ProjectID2  453

struct msg
{
    long msg_type;
    char mgs[BUFFER];
};
