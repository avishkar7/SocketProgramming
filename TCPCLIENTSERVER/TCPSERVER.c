#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555

void main()
{
    int sockfd;
    struct sockaddr_in serverAddr;

    int newSocket;
    struct sockaddr_in newAddr;

    socklen_t addr_size;
    char buf[1024];

    //socket creation
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    printf("Server socket created successfully\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));

    //assign IP, PORT
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //binding newly created socket to given IP
    bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));     
    printf("Bind to port number %d\n", 4455);

    //listening from client
    listen(sockfd, 6);
    printf("Listening..\n");

    //accept data packet from client
    newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

    strcpy(buf, "Hello from Server\n");

    send(newSocket, buf, strlen(buf), 6);

    printf("Closing connection....\n");
}