#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <sys/socket.h>

struct server{
    int listen_fd;
    int client_fd;
    struct sockaddr_in serv_address;
    struct sockaddr_in client_address;
    socklen_t client_address_length;
};

#endif

